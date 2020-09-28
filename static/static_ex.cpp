#include <iostream>
class IDGenerator
{
private:
    IDGenerator(int);
    int s_nextID; // Here's the declaration for a member

public:
    static IDGenerator& getGen(int);
    int getNextID(); // Here's the declaration for a non-static function
};

// Here's the definition of the static member outside the class.  Note we don't use the static keyword here.
// We'll start generating IDs at some random number
//int IDGenerator::s_nextID{ 1 };

IDGenerator& IDGenerator::getGen(int some_ID)
{
    static IDGenerator i(some_ID);
    return i;
}

IDGenerator::IDGenerator(int ID):s_nextID(ID){
};

// Here's the definition of the static function outside of the class.  Note we don't use the static keyword here.
int IDGenerator::getNextID()
{
    return s_nextID++;
}

int main()
{
    IDGenerator myID = IDGenerator::getGen(5);
    for (int count{ 0 }; count < 5; ++count)
        std::cout << "The next ID is: " << myID.getNextID() << '\n';
    return 0;
}
