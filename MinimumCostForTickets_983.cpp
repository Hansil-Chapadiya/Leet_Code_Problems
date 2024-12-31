#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
class MinimumCostForTickets_983
{
private:
public:
    int mincostTickets(std::vector<int> &days, std::vector<int> &costs)
    {
        int max_day = *std::max_element(days.begin(), days.end()) + 1;
        std::vector<int> dp(max_day, 0);
        std::unordered_set<int> travel_days(days.begin(), days.end());

        for (int day = 1; day < max_day; day++)
        {
            if (travel_days.find(day) == travel_days.end())
            {
                dp[day] = dp[day - 1];
            }
            else
            {
                int one_day_pass = dp[day - 1] + costs[0];
                int seven_day_pass = dp[std::max(0, day - 7)] + costs[1];
                int thirty_day_pass = dp[std::max(0, day - 30)] + costs[2];

                dp[day] = std::min({one_day_pass, seven_day_pass, thirty_day_pass});
            }
        }
        return dp[max_day - 1];
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
