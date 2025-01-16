#include <vector>
#include <iostream>
#include <numeric>
#include <climits> // For INT_MAX

class TargetSum_494
{
public:
    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);

        // Check for overflow or invalid cases
        if (total_sum < std::abs(target) || (total_sum + target) % 2 != 0)
        {
            return 0;
        }

        // Avoid potential overflow when computing formula
        long long formula = (total_sum + target) / 2;

        // Check if formula exceeds the limit for vector size
        if (formula > INT_MAX)
        {
            return 0; // Can't handle such large sums
        }

        std::vector<int> dp(static_cast<int>(formula) + 1, 0); // DP array to store the number of ways
        dp[0] = 1;                                             // Base case: There's one way to achieve sum 0

        // Update DP table
        for (auto num : nums)
        {
            for (int j = static_cast<int>(formula); j >= num; j--) // Traverse backwards
            {
                dp[j] += dp[j - num];
            }
        }
        return dp[static_cast<int>(formula)];
    }
};

int main()
{
    TargetSum_494 t1;
    std::vector<int> nums = {100};
    int target = -200;

    std::cout << t1.findTargetSumWays(nums, target) << std::endl; // Output: 0

    return 0;
}
