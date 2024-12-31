#include <iostream>
#include <vector>

class MinimumCostForTickets_983
{
private:
    std::vector<int> travel_days = {1, 7, 30};

public:
    int mincostTickets(std::vector<int> &days, std::vector<int> &costs)
    {
    }
};
int main()
{
    MinimumCostForTickets_983 m1;
    std::vector<int> days = {1, 4, 6, 7, 8, 20};
    std::vector<int> costs = {2, 7, 15};
    std::cout << m1.mincostTickets(days, costs);
    return 0;
}
