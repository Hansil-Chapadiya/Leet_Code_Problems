#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
class MaximumAscendingSubarraySum_1800
{
private:
    std::stack<std::vector<int>> stk;
    bool isAscending(std::vector<int> v)
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

public:
    int maxAscendingSum(std::vector<int> &nums)
    {
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

        int sum = 0;
        while (!stk.empty())
        {
            auto subarray = stk.top();
            stk.pop();
            int subarray_sum = std::accumulate(subarray.begin(), subarray.end(), 0);
            if ((subarray_sum > sum) && isAscending(subarray))
            {

                sum = subarray_sum;
            }
        }
        return sum;
    }
};
int main()
{
    MaximumAscendingSubarraySum_1800 m1;
    // std::vector<int> nums = {10, 20, 30, 5, 10, 50};
    // std::vector<int> nums = {10,20,30,40,50};
    // std::vector<int> nums = {12, 17, 15, 13, 10, 11, 12};
    // std::vector<int> nums = {3,6,10,1,8,9,9,8,9};
    std::vector<int> nums = {38,8,53,18,57,44,56,58,57,93,56,12,89,75,37,45,57,40,67,100,6,92,100,87,47,67,47,38,16,21,48,29,21,61,29,84,9,23,43,22,84,50,7,21,70,31,30,22,2,76,33,25,11,51,74,95,94,2,50,49,55,43,93,60,44,97,52,1,63,97,66,20,84,4,85,14,85,18,15,26,51,70,52,8,95,84,37,4,41,97,96,17,20,98,34,70,93,83,81,62};
    std::cout << m1.maxAscendingSum(nums);
    return 0;
}