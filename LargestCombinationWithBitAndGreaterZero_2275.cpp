#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
class LargestCombinationWithBitAndGreaterZero_2275
{
private:
    std::unordered_map<int, int> bitcount_map;

public:
    int largestCombination(std::vector<int> &candidates)
    {
        int i = 0;

        // Count the bits set for each bit position from 0 to 23
        while (i < 24)
        {
            for (auto &num : candidates)
            {
                if ((num & (1 << i)) != 0)
                {
                    bitcount_map[i]++;
                }
            }
            i++;
        }

        // Find the bit position with the maximum count
        auto max_size = std::max_element(bitcount_map.begin(), bitcount_map.end(),
                                         [](const auto &lhs, const auto &rhs)
                                         {
                                             return lhs.second < rhs.second;
                                         });

        return max_size->second; // Returns the maximum count of set bits
    }
};
int main()
{
    LargestCombinationWithBitAndGreaterZero_2275 l1;
    // std::vector<int> candidates = {16,17,71,62,12,24,14};
    std::vector<int> candidates = {8, 8};
    std::cout << l1.largestCombination(candidates);
    return 0;
}