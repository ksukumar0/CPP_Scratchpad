#include<iostream>
#include<string>

using namespace std;

class func
{
    public:
        func():m_count(0){};
        func(int a):m_count(a){};
        func(func & t)
        {
            cout<<"In copy constructor"<<endl;
            this->m_count = t.m_count;
        }
        func & operator=(const func &rhs)
        {
            cout<<"In assignment operator"<<endl;
            return *this;
        }
        void print()
        {
            cout<<"Count: "<<m_count<<endl;
        }
    private:
        int m_count;
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
