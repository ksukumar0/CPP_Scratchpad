#include<iostream>

#include<iomanip>
#include<string>

using namespace std;

class func
{
    public:
        func(int mult) : m_multiplier(mult){
        }
        int operator () (int toMult)
        {
            return m_multiplier*toMult;
        }
    private:
        int m_multiplier;
};

int main()
{
    func mul8(8), mul64(64);
    int n = 6;
    cout<<n<<"*8 is "<<mul8(6)<<endl;
    cout<<n<<"*64 is "<<mul64(6)<<endl;
    return 0;
}
