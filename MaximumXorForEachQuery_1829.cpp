#include <iostream>
#include <vector>
class MaximumXorForEachQuery
{
private:
    /* data */
public:
    std::vector<int> getMaximumXor(std::vector<int> &nums, int maximumBit)
    {
        // int xor_product = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     xor_product ^= nums[i];
        // }

        // std::vector<int> ans(nums.size(), 0);
        // int mask = (1 << maximumBit) - 1;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int k = xor_product ^ mask;
        //     ans[i] = k;
        //     xor_product ^= nums[nums.size() - 1 - i];
        // }
        // return ans;

        std::vector<int> xor_product(nums.size());
        for (int i = 1; i < nums.size(); i++)
        {
            xor_product[i] = xor_product[i -1] ^ nums[i];
        }

        std::vector<int> ans(nums.size(), 0);
        int mask = (1 << maximumBit) - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int product = xor_product[nums.size() - 1 - i];
            ans[i] = product ^ mask;
        }
        return ans;
    }
};
int main()
{
    MaximumXorForEachQuery m1;
    std::vector<int> nums = {0, 1, 1, 3};
    std::vector<int> ans = m1.getMaximumXor(nums, 2);
    for (auto num : ans)
    {
        std::cout<<num<<" ";
    }

    return 0;
}
