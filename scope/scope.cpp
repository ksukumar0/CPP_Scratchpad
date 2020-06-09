#include<iostream>
#include<string>

class Entity
{
    public:
        Entity() : m_Name("Unknown") {}
        Entity(const std::string& name) : m_Name(name) {}

        const std::string& getName() const
        {
            return m_Name;
        }
    private:
        std::string m_Name;
};

int main()
{
    Entity e = Entity();
    Entity e1 = Entity("HiThere");

    std::cout<<e.getName()<<std::endl;
    std::cout<<e1.getName();
    return 0;
}
