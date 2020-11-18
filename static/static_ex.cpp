#include <iostream>
class IDGenerator
{
private:
    IDGenerator(int);
    int s_nextID; // Here's the declaration for a member

public:
    static IDGenerator& getGen(int);
    int getNextID(); // Here's the declaration for a non-static function
    IDGenerator & operator= (const IDGenerator & rhs) = delete;
    IDGenerator (const IDGenerator &);
};

// Here's the definition of the static member outside the class.  Note we don't use the static keyword here.
// We'll start generating IDs at some random number
//int IDGenerator::s_nextID{ 1 };

IDGenerator& IDGenerator::getGen(int some_ID)
{
    static IDGenerator initial(some_ID);
    return initial;
}

IDGenerator::IDGenerator(int ID):s_nextID(ID){
    std::cout<<"The constructor is called"<<std::endl;
};

IDGenerator::IDGenerator(const IDGenerator &rhs){
    std::cout<<"The COPY constructor is called"<<std::endl;
    s_nextID = rhs.s_nextID;
}

// Here's the definition of the static function outside of the class.  Note we don't use the static keyword here.
int IDGenerator::getNextID()
{
    return s_nextID++;
}

int main()
{
    IDGenerator myID = IDGenerator::getGen(5);
    IDGenerator myID1 = IDGenerator::getGen(15);
    for (int count{ 0 }; count < 5; ++count)
    {
        std::cout << "The next ID is: " << myID.getNextID() << '\n';
        std::cout << "The next ID1 is: " << myID1.getNextID() << '\n';
    }
    return 0;
}
