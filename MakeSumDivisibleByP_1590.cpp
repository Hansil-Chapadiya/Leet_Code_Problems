#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

class MakeSumDivisibleByP_1590
{
public:
    int minSubarray(std::vector<int> &nums, int p)
    {
        // Calculate total sum of the array
        long long total_sum = std::accumulate(nums.begin(), nums.end(), 0LL);

        // Calculate the target remainder that needs to be removed
        int target_remainder = total_sum % p;

        // If the total sum is already divisible by p, no need to remove any subarray
        if (target_remainder == 0)
            return 0;

        // Hash map to store the latest index of each remainder of prefix sums
        std::unordered_map<int, int> remainder_index;
        remainder_index[0] = -1; // For subarrays starting from index 0

        int prefix_sum = 0;
        int min_length = nums.size();

        // Iterate through the array to compute prefix sums and find the smallest subarray
        for (int i = 0; i < nums.size(); ++i)
        {
            prefix_sum = (prefix_sum + nums[i]) % p;

            // Calculate the remainder we need to find in the hash map
            int needed_remainder = (prefix_sum - target_remainder + p) % p;

            // Check if the needed remainder is in the hash map
            if (remainder_index.find(needed_remainder) != remainder_index.end())
            {
                // Update the minimum length of subarray to be removed
                min_length = std::min(min_length, i - remainder_index[needed_remainder]);
            }

            // Update the remainder index map with the current remainder
            remainder_index[prefix_sum] = i;
        }

        // If we never found a valid subarray, return -1
        return min_length == nums.size() ? -1 : min_length;
    }
};

int main()
{
    MakeSumDivisibleByP_1590 solution;
    std::vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    std::cout << solution.minSubarray(nums, p) << std::endl; // Expected output: 1
    return 0;
}
