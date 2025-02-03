#include <iostream>
#include <vector>
#include <stack>
// #include <algorithm>
class LongestStrictlyIncreasingStrictlyDecreasingSubarray_3105
{
private:
    bool isIncreasing(std::vector<int> v)
    {
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i - 1] >= v[i])
            {
                return false;
            }
        }
        return true;
    }
    bool isDecreasing(std::vector<int> v)
    {
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i - 1] <= v[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    int longestMonotonicSubarray(std::vector<int> &nums)
    {
        std::stack<std::vector<int>> stk;
        for (int i = 0; i < nums.size(); i++)
        {
            std::vector<int> temp;
            for (int j = i; j < nums.size(); j++)
            {
                temp.push_back(nums[j]);
                stk.push(temp);
            }
            temp.clear();
        }

        int max_len = 0;
        while (!stk.empty())
        {
            auto subarry = stk.top();
            stk.pop();
            if (isIncreasing(subarry) || isDecreasing(subarry))
            {
                max_len = std::max(max_len, (int)subarry.size());
            }
        }
        return max_len;
    }
};
int main()
{
    LongestStrictlyIncreasingStrictlyDecreasingSubarray_3105 l1;
    // std::vector<int> nums = {1, 4, 3, 3, 2};
    // std::vector<int> nums = {3,3,3,3};
    std::vector<int> nums = {3, 2, 1};
    std::cout << l1.longestMonotonicSubarray(nums);
    return 0;
}
