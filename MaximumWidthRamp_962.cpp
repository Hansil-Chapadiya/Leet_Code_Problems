#include <iostream>
#include <vector>
#include <stack>

class MaximumWidthRamp_962
{
public:
    int maxWidthRamp(std::vector<int> &nums)
    {
        std::stack<int> stk;

        // Step 1: Build a decreasing stack of indices
        for (int i = 0; i < nums.size(); i++)
        {
            if (stk.empty() || nums[stk.top()] > nums[i])
            {
                stk.push(i); // Only push index if nums[i] is smaller than the current top
            }
        }

        int maxWidth = 0;

        // Step 2: Traverse from the end and calculate maxWidth ramp
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            // While stack is not empty and current nums[i] is >= nums at index from stack
            while (!stk.empty() && nums[i] >= nums[stk.top()])
            {
                maxWidth = std::max(maxWidth, i - stk.top()); // Calculate the width
                stk.pop();                                    // Pop the index because we found the max ramp with it
            }
        }

        return maxWidth;
    }
};

int main()
{
    MaximumWidthRamp_962 m1;
    std::vector<int> nums = {6, 0, 8, 2, 1, 5};
    std::cout << "Maximum Width Ramp: " << m1.maxWidthRamp(nums) << std::endl;
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();