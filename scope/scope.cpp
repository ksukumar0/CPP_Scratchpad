#include<iostream>
#include<string>

class Entity
{
    public:
        Entity() : m_Name("Unknown") {}
        Entity(const std::string& name) : m_Name(name) {}

        ~Entity(){
            std::cout<<"Destroying... "<<m_Name<<std::endl;
        }
        const std::string& getName() const
        {
            return m_Name;
        }
    private:
        std::string m_Name;
};

int main()
{
    Entity *e;
    Entity e1 = Entity("HiThere");
    {
        Entity entity = Entity("InScope");
        //std::cout<<e.getName()<<std::endl;
        e = &entity;
        std::cout<<entity.getName()<<std::endl;
    }
    std::cout<<e->getName()<<std::endl;
    return 0;
}
