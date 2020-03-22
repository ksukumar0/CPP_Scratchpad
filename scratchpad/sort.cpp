#include <iostream>
#include <algorithm>
//#include <bits/stdc++.h>
#include <vector>

static void printArray(std::vector<int> &values, const char *textToPrintBefore)
{
    std::cout<<textToPrintBefore<<'\n';
    for(auto i: values)
    {
        std::cout<<i<<' ';
    }
    std::cout<<'\n';
}

int sort_cpp_style()
{
    std::vector<int> values{1341,12341,362,841,79,11,434,29,152,178,1};
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
