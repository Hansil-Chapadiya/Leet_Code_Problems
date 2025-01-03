#include <iostream>
#include <vector>
class NumberOfWaystoSplitArray_2270
{
private:
    /* data */
public:
    int waysToSplitArray(std::vector<int> &nums)
    {
        int valid_splits = 0;
        std::vector<long long> prefix_sum(nums.size());
        prefix_sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        long long total_sum = prefix_sum[nums.size() - 1]; // Total sum of the array
        for (int i = 0; i < nums.size() - 1; i++)          // Split at i, so the right part starts at i + 1
        {
            if (prefix_sum[i] >= total_sum - prefix_sum[i])
            {
                valid_splits++;
            }
        }
        return valid_splits;
    }
};
int main()
{
    // std::vector<int> nums = {10, 4, -8, 7};
    std::vector<int> nums = {9, 9, 9};
    NumberOfWaystoSplitArray_2270 n1;
    std::cout << n1.waysToSplitArray(nums);
    return 0;
}