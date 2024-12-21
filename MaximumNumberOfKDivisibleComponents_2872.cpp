#include <iostream>
#include <vector>

class MaximumNumberOfKDivisibleComponents_2872
{
private:
    /* data */
public:
    int maxKDivisibleComponents(int n, std::vector<std::vector<int>> &edges, std::vector<int> &values, int k)
    {
    }
};

MaximumNumberOfKDivisibleComponents_2872::MaximumNumberOfKDivisibleComponents_2872(/* args */)
{
}

MaximumNumberOfKDivisibleComponents_2872::~MaximumNumberOfKDivisibleComponents_2872()
{
}
int main()
{
    std::vector<std::vector<int>> edges = {{0, 2},
                                           {1, 2},
                                           {1, 3},
                                           {2, 4}};
    std::vector<int> values = {1, 8, 1, 4, 4};
    MaximumNumberOfKDivisibleComponents_2872 m1;
    m1.maxKDivisibleComponents(5, edges, values, 6);
    return 0;
}
