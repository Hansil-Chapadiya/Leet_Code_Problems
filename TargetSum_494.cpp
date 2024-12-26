#include <vector>
#include <iostream>
#include <numeric>
class TargetSum_494
{
private:
    /* data */
public:
    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
    }
};
int main()
{
    TargetSum_494 t1;
    std::vector<int> nums = {1, 1, 1, 1, 1};
    t1.findTargetSumWays(nums, 5);
    return 0;
}