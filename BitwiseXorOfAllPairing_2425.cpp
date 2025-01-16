#include <iostream>
#include <vector>
class BitwiseXorOfAllPairing_2425
{
private:
    /* data */
public:
    int xorAllNums(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<long long> result;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == 0)
            {
                for (int j = 0; j < nums2.size(); j++)
                {
                    result.push_back(nums2[j]);
                }
            }
            else
            {
                for (int j = 0; j < nums2.size(); j++)
                {
                    if (nums1[i] == nums2[j])
                    {
                        result.push_back(0);
                    }
                    else
                    {
                        result.push_back(nums1[i] ^ nums2[j]);
                    }
                }
            }
        }
        int cummalative_xor = 0;
        for (auto i : result)
        {
            cummalative_xor ^= i;
        }
        return cummalative_xor;
    }
};
int main()
{
    BitwiseXorOfAllPairing_2425 b1;
    std::vector<int> nums1 = {2, 1, 3};
    std::vector<int> nums2 = {10, 2, 5, 0};
    std::cout << b1.xorAllNums(nums1, nums2);
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();