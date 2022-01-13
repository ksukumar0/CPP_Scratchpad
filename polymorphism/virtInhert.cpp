// C++ program for function overriding

#include <bits/stdc++.h>
#include "MdBgaIoIsr.h"
using namespace std;

class base
{
    public:
        virtual void print ()
        { cout<< "print base class" <<endl; }

        void show ()
        { cout<< "show base class" <<endl; }
};

class derived:public base
{
    public:
        void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly
        { cout<< "print derived class" <<endl; }

        void show ()
        { cout<< "show derived class" <<endl; }

        void show1()
        { cout<< "show1 derived class" <<endl; }
};

class derived2:public derived
{
    public:
        void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly
        { cout<< "print derived2 class" <<endl; }

        void show ()
        { cout<< "show derived2 class" <<endl; }
};

class FswMdBgaIoIsr : public MdBgaIoIsr
{
    public:
        FswMdBgaIoIsr();
        ~FswMdBgaIoIsr();
        void IsrThread(void) override;
};

FswMdBgaIoIsr::FswMdBgaIoIsr()
{
}

FswMdBgaIoIsr::~FswMdBgaIoIsr()
{
}

void FswMdBgaIoIsr::IsrThread(void)
{
    cout<<"In FswMdBgaIoIsr"<<endl;
}

static void printClass(base *bptr)
{
    //virtual function, bound at runtime (Runtime polymorphism)
    bptr->print();

    // Non-virtual function, bound at compile time
    bptr->show();

}

void testVirtKeyword(void)
{
    derived d;
    derived2 d2;
    base *bptr;
    bptr = &d;
    derived *pt = dynamic_cast<derived *>(bptr);
    pt->show1();
    printClass(bptr);
    bptr = &d2;
    printClass(bptr);
}

void testThisPointer()
{
    FswMdBgaIoIsr t;
    t.IsrThread();
}

//main function
int main()
{
    testVirtKeyword();
    testThisPointer();
    return 0;
}
