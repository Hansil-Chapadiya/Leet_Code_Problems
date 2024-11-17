#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

class ShortestSubArrayAtLeastK_862
{
public:
    int shortestSubarray(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        std::vector<int> prefix_sum(n + 1, 0);
        std::deque<int> prefix_sum_indices;
        int min_len = INT_MAX;

        // Compute prefix sums
        for (int i = 1; i < n + 1; i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }

        // Process each prefix sum
        for (int i = 0; i < prefix_sum.size(); i++)
        {
            // Check if a valid subarray is found
            while (!prefix_sum_indices.empty() && (prefix_sum[i] - prefix_sum[prefix_sum_indices.front()] >= k))
            {
                min_len = std::min(min_len, i - prefix_sum_indices.front());
                prefix_sum_indices.pop_front();
            }

            // Maintain increasing order in deque
            while (!prefix_sum_indices.empty() && prefix_sum[i] <= prefix_sum[prefix_sum_indices.back()])
            {
                prefix_sum_indices.pop_back();
            }

            // Add current index to deque
            prefix_sum_indices.push_back(i);
        }

        return min_len == INT_MAX ? -1 : min_len;
    }
};

int main()
{
    std::vector<int> nums = {2, -1, 2};
    ShortestSubArrayAtLeastK_862 s1;
    std::cout << s1.shortestSubarray(nums, 3) << std::endl;
    return 0;
}
