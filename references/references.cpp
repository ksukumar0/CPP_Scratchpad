#include<iostream>

#include<iomanip>
#include<string>

using namespace std;

int k=10;
int nmi;
static int plis;
static int blush=10;

int fun(const int &x)
{
     return x;
}

int main()
{
    int number1 = 88, number2 = 22;
    int x = fun(number1);
    (void) x;
    (void) nmi;
    (void) plis;
    (void) blush;
    
    // Create a pointer pointing to number1
    int * pNumber1 = &number1;  // Explicit referencing
    *pNumber1 = 99;             // Explicit dereferencing
    cout << *pNumber1 << endl;  // 99
    cout << &number1 << endl;   // 0x22ff18
    cout << pNumber1 << endl;   // 0x22ff18 (content of the pointer variable - same as above)
    cout << &pNumber1 << endl;  // 0x22ff10 (address of the pointer variable)
    pNumber1 = &number2;        // Pointer can be reassigned to store another address

    // Create a reference (alias) to number1
    int & refNumber1 = number1;  // Implicit referencing (NOT &number1)
    refNumber1 = 11;             // Implicit dereferencing (NOT *refNumber1)
    cout << refNumber1 << endl;  // 11
    cout << &number1 << endl;    // 0x22ff18
    cout << &refNumber1 << endl; // 0x22ff18
    //refNumber1 = &number2;     // Error! Reference cannot be re-assigned
    // error: invalid conversion from 'int*' to 'int'
    refNumber1 = number2;        // refNumber1 is still an alias to number1.
    // Assign value of number2 (22) to refNumber1 (and number1).
    number2++;   
    cout << refNumber1 << endl;  // 22
    cout << number1 << endl;     // 22
    cout << number2 << endl;     // 23

    int j=10;
    const int &ref = j;
    (void) ref;

    int i = 5;
    int *p;
    int *&r = p;
    p = &i;
    cout <<endl<<endl<<"The value of p is "<<p<<endl;
    cout <<endl<<endl<<"The value of *p is "<<*p<<endl;
    cout <<endl<<endl<<"The value of r is "<<r<<endl;
    cout <<endl<<endl<<"The value of *r is "<<*r<<endl;

    (void) i;
    (void) p;
    (void) r;

/*
    std::cout << 1331 << std::endl;
    std::cout << "In hex " << std::hex << 1331 << std::endl;
    std::cout << 1331.123456 << std::endl;
    std::cout.setf(std::ios::scientific, std::ios::floatfield);
    std::cout << 1331.123456 << std::endl;
    std::cout << std::setprecision(3) << 1331.123456 << std::endl;
    std::cout << std::dec << 1331 << std::endl;
    std::cout.fill('X');
    std::cout.width(8);
    std::cout << 1331 << std::endl;
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout.width(8);
    std::cout << 1331 << std::endl;


    std::string name,greeting;
    std::cout << "Please enter your first name: ";
    while(std::cin >> name) {
        greeting = "Hello, " + name + "!";
        std::cout << greeting << std::endl << std::endl;
        std::cout << "Please enter your first name: ";
    }
    int j1{};
    int j2{};
    cout << j1 << " " <<j2<<endl;
    */
    return 0;
}
