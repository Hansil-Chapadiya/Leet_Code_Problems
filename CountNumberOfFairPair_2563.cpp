#include <iostream>
#include <vector>
#include <algorithm>

class CountNumberOfFairPair_2563
{
public:
    long long countFairPairs(std::vector<int> &nums, int lower, int upper)
    {
        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());
        long long cnt = 0;

        // Step 2: Use two pointers to find pairs within range
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;

            // Find the lowest index where nums[i] + nums[left] >= lower
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums[i] + nums[mid] < lower)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            int lowerBound = left;

            // Reset pointers to find the highest index where nums[i] + nums[right] <= upper
            left = i + 1;
            right = nums.size() - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums[i] + nums[mid] > upper)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            int upperBound = right;

            // Count valid pairs in the range [lowerBound, upperBound]
            cnt += std::max(0, upperBound - lowerBound + 1);
        }

        return cnt;
    }
};

int main()
{
    CountNumberOfFairPair_2563 c1;
    std::vector<int> nums = {0, 1, 7, 4, 4, 5}; // Sorted: 0, 1, 4, 4, 5, 7
    std::cout << c1.countFairPairs(nums, 3, 6) << std::endl;
    return 0;
}
