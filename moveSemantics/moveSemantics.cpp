#include<iostream>
#include<string>

using namespace std;

class func
{
    public:
        func():m_count(0){
            space = nullptr;
        };
        func(int a):m_count(a){
            space = nullptr;
        };
        func(func & t)
        {
            cout<<"In copy constructor"<<endl;
            this->m_count = t.m_count;
            space = new int;
        }
        func & operator=(const func &rhs)
        {
            cout<<"In assignment operator"<<endl;
            return *this;
        }
        func& operator=(func&& rhs)
        {
            delete space;
            this->m_count = rhs.m_count;
            this->space = rhs.space;
            return *this;
        }
        void print()
        {
            cout<<"Count: "<<m_count<<endl;
        }
    private:
        int m_count;
        int *space;
};

int main()
{
    func g(5);
    func t(g);
    func *h = new func(23);
    t.print();
    h->print();

    return 0;
}
