#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

class ContinuousSubArray_2762
{
public:
    long long continuousSubarrays(std::vector<int> &nums)
    {
        long long count = 0;
        int left = 0;
        std::deque<int> minDeque, maxDeque;

        for (int right = 0; right < nums.size(); ++right)
        {
            // Maintain the minimum deque
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right])
                minDeque.pop_back();
            minDeque.push_back(right);

            // Maintain the maximum deque
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right])
                maxDeque.pop_back();
            maxDeque.push_back(right);

            // Check if the current window [left, right] satisfies |nums[i1] - nums[i2]| <= 2
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2)
            {
                if (minDeque.front() == left)
                    minDeque.pop_front();
                if (maxDeque.front() == left)
                    maxDeque.pop_front();
                left++;
            }

            // The number of subarrays ending at index 'right' is (right - left + 1)
            count += (right - left + 1);
        }

        return count;
    }
};

int main()
{
    std::vector<int> nums = {5, 4, 2, 4};
    ContinuousSubArray_2762 c1;
    std::cout << c1.continuousSubarrays(nums) << std::endl;
    return 0;
}

static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
