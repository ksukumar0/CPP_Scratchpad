#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

// helper class for runtime polymorphism demo below
struct B {
    virtual void bar() { std::cout << "B::bar\n"; }
    virtual ~B() = default;
};
struct D : B
{
    D() { std::cout << "D::D\n";  }
    D(int a) { std::cout <<"D::D="<<a<<"\n";}
    D& operator= (D &&)
    {
       std::cout<<"Assignment D::=\n";
       return *this;
    }
    ~D() { std::cout << "D::~D\n";  }
    void bar() override { std::cout << "D::bar\n";  }
};

class IBase
{
    public:
        virtual void printValue(void)
        {
            std::cout<<"In Base"<<std::endl;
        }
        virtual ~IBase(){}
    protected:
        bool m_isIt;
};

class CDerived : public IBase
{
public:
    std::unique_ptr<IBase> createIBase(void)
    {
        return std::make_unique<CDerived>();
    }
    void printValue() override
    {
        m_isIt = true;
        std::cout<<"In Derived"<<std::endl;
    }
    ~CDerived()
    {

    }
};

// a function consuming a unique_ptr can take it by value or by rvalue reference
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}

// helper function for the custom deleter demo below
void close_file(std::FILE* fp) { std::fclose(fp); }

// unique_ptr-based linked list demo
struct List {
    struct Node {
        int data;
        std::unique_ptr<Node> next;
        Node(int data) : data{data}, next{nullptr} {}
    };
    List() : head{nullptr} {};
    // N.B. iterative destructor to avoid stack overflow on long lists
    ~List() { while(head) head = std::move(head->next); }
    // copy/move and other APIs skipped for simplicity
    void push(int data) {
        auto temp = std::make_unique<Node>(data);
        if(head) temp->next = std::move(head);
        head = std::move(temp);
    }
    private:
    std::unique_ptr<Node> head;
};

void test1(void)
{
    std::cout << "1) Unique ownership semantics demo\n";
    {
        auto p = std::make_unique<D>(); // p is a unique_ptr that owns a D
        auto q = pass_through(std::move(p)); 
        assert(!p); // now p owns nothing and holds a null pointer
        q->bar();   // and q owns the D object
    } // ~D called here

    std::cout << "2) Runtime polymorphism demo\n";
    {
        std::unique_ptr<B> p = std::make_unique<D>(); // p is a unique_ptr that owns a D
        // as a pointer to base
        p->bar(); // virtual dispatch

        std::vector<std::unique_ptr<B>> v;  // unique_ptr can be stored in a container
        v.push_back(std::make_unique<D>());
        v.push_back(std::move(p));
        v.emplace_back(new D);
        for(auto& p: v) p->bar(); // virtual dispatch
    } // ~D called 3 times

    std::cout << "3) Custom deleter demo\n";
    std::ofstream("demo.txt") << 'x'; // prepare the file to read
    {
        std::unique_ptr<std::FILE, decltype(&close_file)> fp(std::fopen("demo.txt", "r"),
                &close_file);
        if(fp) // fopen could have failed; in which case fp holds a null pointer
            std::cout << (char)std::fgetc(fp.get()) << '\n';
    } // fclose() called here, but only if FILE* is not a null pointer
    // (that is, if fopen succeeded)

    std::cout << "4) Custom lambda-expression deleter demo\n";
    {
        std::unique_ptr<D, std::function<void(D*)>> p(new D, [](D* ptr)
                {
                std::cout << "destroying from a custom deleter...\n";
                delete ptr;
                });  // p owns D
        p->bar();
    } // the lambda above is called and D is destroyed

    std::cout << "5) Array form of unique_ptr demo\n";
    {
        std::unique_ptr<D[]> p(new D[3]);
    } // calls ~D 3 times

    std::cout << "6) Linked list demo\n";
    {
        List l;
        for(long n = 0; n != 1'000'000; ++n) l.push(n);
        std::cout << "destroying 1'000'000 nodes... ";
    } // destroys all 1 million nodes
    std::cout << "Done.\n";

}

void test2(void)
{
    std::unique_ptr<D> pOutBuffer( new D ); // Allocation on Stack failed. Size is too large. 
    D& outBuffer = *pOutBuffer;
    (void) outBuffer;

    return;
}

std::unique_ptr<D> test3(void)
{
    return std::unique_ptr<D>(new D(2));
}

void test4(void)
{
    std::unique_ptr<CDerived> test;
    std::unique_ptr<IBase> pBase = test->createIBase();
    pBase->printValue();
}

int main()
{
    test1();
    //test2();
    auto s = test3();
    (void) s;
    test4();
}
