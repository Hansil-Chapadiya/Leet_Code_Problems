#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
class MaximumSumOfDistnictSubArrayWithLengthK_2461
{
private:
    /* data */
public:
    long long maximumSubarraySum(std::vector<int> &nums, int k)
    {

        // auto unique = std::unique(nums.begin(), nums.end());
        // nums.erase(unique, nums.end());

        // if (nums.size() < k)
        // {
        //     return 0;
        // }
        long long max = 0;
        for (int i = 0; i < (nums.size() - k + 1); i++)
        {
            std::unordered_set<int> uniqueElements;
            long long sum = 0;
            bool isUnique = true;

            for (int j = 0; j < k; j++)
            {
                int currentElement = nums[i + j];
                if (uniqueElements.count(currentElement) > 0)
                {
                    isUnique = false; // Subarray has duplicates
                    break;
                }
                uniqueElements.insert(currentElement);
                sum += nums[i + j];
            }
            // If all elements in the subarray are unique, update maxSum
            if (isUnique)
            {
                max = std::max(max, sum);
            }
        }
        return max;
    }
};
int main()
{
    MaximumSumOfDistnictSubArrayWithLengthK_2461 m1;
    std::vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    std::cout << m1.maximumSubarraySum(nums, 3);
    // std::vector<int> nums = {9221, 8838, 520, 9644, 9511, 2847, 6495, 3028, 6180, 8646, 2933, 8471, 9249, 1600, 3696, 1444, 4071, 2501, 1174, 7979, 1665, 79, 3614, 521, 796, 2538, 3796, 9663, 113, 4701, 1750, 9715, 6040, 2221, 815, 4198, 7701, 4180, 5283, 9981, 5481, 7766, 3824, 2058, 257, 2552, 91, 6655, 2793, 9059, 8097, 4579, 3689, 7926, 5585, 5161, 1973, 8306, 8231, 8956, 778, 842, 4200, 1892, 8572, 2596, 4435, 1587, 5310, 5982, 2889, 3361, 868, 2513, 1077, 268, 3777, 2864, 6307, 2992, 5693, 9435, 4813, 5396, 4110, 8057, 5205, 3309, 7506, 9547, 4544, 7834, 1390, 8026, 7452, 1310, 6443, 4404, 271, 9544, 9824, 3173, 2044, 915, 613, 932, 1015, 8978, 6241, 900, 6517, 1279, 6179, 3615, 6418, 52, 558, 282, 8507, 7252, 7307, 1313, 7371, 5952, 7756, 394, 81, 4742, 2228, 7002, 2598, 3510, 4206, 7978, 7258, 4652, 7080, 6669, 5789, 6993, 9795, 4712, 3244, 1654, 365, 1522, 8920, 7726, 4771, 1908, 9326, 3313, 199, 7724, 6482, 8033, 535, 3627, 4965, 3139, 6708, 5398, 4441, 4639, 1739, 8983, 1187, 7810, 558, 2178, 6755, 4735, 2175, 7503, 3812, 4533, 29, 4225, 288, 7};
    // std::cout << m1.maximumSubarraySum(nums, 494);
    // std::vector<int> nums = {4, 4, 4};
    // std::cout << m1.maximumSubarraySum(nums, 3);
    // std::vector<int> nums = {3, 3, 5, 5, 3, 3, 1, 1, 4, 2, 5, 1};
    // std::cout << m1.maximumSubarraySum(nums, 4);
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();