#include <iostream>
using namespace std;

class Base {
public:
    void NonVirtual() {
        cout << "Base NonVirtual called.\n";
    }
    virtual void Virtual() {
        cout << "Base Virtual called.\n";
    }
    void test(){
        cout << "Check\n";
    }
};
class Derived : public Base {
public:
    void NonVirtual() {
        cout << "Derived NonVirtual called.\n";
    }
    void Virtual() {
        cout << "Derived Virtual called.\n";
    }
};

int main() {
    Base* bBase = new Base();
    Base* bDerived = new Derived();
    bBase->NonVirtual();
    bBase->Virtual();
    bDerived->NonVirtual();
    bDerived->Virtual();
    bDerived->test();

    Base bBase1;
    Derived bDerived1;
    bBase1.NonVirtual();
    bBase1.Virtual();
    bDerived1.NonVirtual();
    bDerived1.Virtual();
    bDerived1.test();

}
