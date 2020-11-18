#include <iostream>
#include <algorithm>
#include <vector>

class a
{
    public:
        int b;
        a(int value):b(value){};
};

static void printArray(std::vector<int> &values, const char *textToPrintBefore)
{
    std::cout<<textToPrintBefore<<'\n';
    for(auto i: values)
    {
        std::cout<<i<<' ';
    }
    std::cout<<'\n';
}

static void printVector(std::vector<a> &vect, const char *textToPrintBefore)
{
    std::cout<<textToPrintBefore<<'\n';
    for(auto i: vect)
    {
        std::cout<<i.b<<' ';
    }
    std::cout<<'\n';
}

bool compare(const a &first, const a &second)
{
    return (first.b < second.b);
}

int sort_cpp_style()
{
    std::vector<int> values{1341,12341,362,841,79,11,434,29,152,178,1};

    std::vector<a> vecA;
    for (auto i: values)
    {
        vecA.push_back(a(i));
    }
    std::cout<<"Size of Vector is "<<vecA.size()<<'\n';
    std::cout<<"Sorting a Vector of Classes"<<'\n';
    printVector(vecA,"Before Sorting");
    std::sort(std::begin(vecA),std::end(vecA), compare);
    printVector(vecA,"After Sorting");

    std::cout<<"\n\n";
    std::cout<<"Sorting Array of Ints"<<'\n';
    printArray(values,"Before Sorting");
    values.push_back(454);
    std::sort(std::begin(values), std::end(values));
    printArray(values,"After Sorting");
    return values[0];
}

int main(void)
{
    sort_cpp_style();
}
