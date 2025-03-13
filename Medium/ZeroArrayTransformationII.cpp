#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
class ZeroArrayTransformationII
{
public:
    bool isZeroVector(const std::vector<int> &nums)
    {
        return std::all_of(nums.begin(), nums.end(), [](int i)
                           { return i == 0; });
    }
    int minZeroArray(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
    {
        int k = 0;
        for (auto range : queries) // o(q)
        {
            int start = range[0];
            int end = range[1];
            int diffValue = range[2];
            int zeroCount = 0;
            for (int i = start; i <= end; i++) // o(q * r)
            {
                if (nums[i] != 0)
                {
                    nums[i] -= diffValue;
                }
                if (nums[i] <= 0)
                {
                    nums[i] = 0;
                }
            }
            if (isZeroVector(nums)) // o(q * r * n)
            {
                k++;
                return k;
            }
            else
            {
                k++;
            }
        }
        return -1;
    }
};

int main()
{
    ZeroArrayTransformationII z1;
    // std::vector<int> nums = {2,0,2};
    std::vector<int> nums = {4, 3, 2, 1};
    // std::vector<std::vector<int>> queries = {{0,2,1},{0,2,1},{1,1,3}};
    std::vector<std::vector<int>> queries = {{1, 3, 2}, {0, 2, 1}};
    std::cout << z1.minZeroArray(nums, queries);

    return 0;
}