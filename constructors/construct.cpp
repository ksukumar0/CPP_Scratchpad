#include <iostream>
#include <string>

class MyClass
{
    public:
    MyClass() : name("Unknown")
    {
        std::cout << "run constructor MyClass::MyClass()" << name << std::endl; 
    }
    ~MyClass() 
    {
        std::cout << "run destructor MyClass::~MyClass() "<< name << std::endl;
    }
    MyClass(const std::string &p)
    {
        name = p;
        std::cout << "run constructor MyClass::MyClass() " << name << std::endl; 
    }

    MyClass(const MyClass& x)
    {
        std::cout << "run copy constructor MyClass::MyClass(const MyClass&)" << std::endl;
    }
    MyClass& operator = (const MyClass& x)
    {
        std::cout << "run assignment MyClass::operator=(const MyClass&)" << std::endl;
        name = x.name + "_Copy";
        return *this;
    }
    private:
    std::string name;
};

MyClass my_function(std::string name)
{
    std::cout << "run my_function()" << std::endl;
    MyClass a(name);
    std::cout << "my_function is going to return a..." << std::endl;
    return a;
}

int main(int argc, char** argv)
{
    MyClass b = my_function("myFunc1");

    MyClass c("C");
    c = my_function("myFunc2");

    return 0;
}
