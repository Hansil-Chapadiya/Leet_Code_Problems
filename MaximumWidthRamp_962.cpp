#include <iostream>
#include <vector>
#include <stack>
class MaximumWidthRamp_962
{
private:
    std::stack<int> stk;

public:
    int maxWidthRamp(std::vector<int> &nums)
    {
        for (int i : nums)
        {
            stk.push(i);
        }
        int maxWidth = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!stk.empty() && nums[stk.top()] > nums[i])
            {
                maxWidth = std::max(maxWidth, i - stk.top());
            }
        }
        return maxWidth;
    }
};
int main()
{
    return 0;
}