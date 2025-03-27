#include <iostream>
#include <unordered_map>
#include <vector>

class MinimumIndexofValidSplit_2780
{
public:
    int minimumIndex(std::vector<int> &nums)
    {
        std::unordered_map<int, int> freqMap;
        for (int num : nums)
        {
            freqMap[num]++;
        }

        int dominant = -1;
        for (auto &[key, value] : freqMap)
        {
            if (value * 2 > nums.size())
            {
                dominant = key;
                break;
            }
        }

        if (dominant == -1)
            return -1; // No dominant element found

        std::unordered_map<int, int> f1, f2 = freqMap;
        int leftSize = 0, rightSize = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            f1[nums[i]]++; // Increase left frequency
            f2[nums[i]]--; // Decrease right frequency
            leftSize++;
            rightSize--;

            if (f2[nums[i]] == 0)
                f2.erase(nums[i]); // Remove if zero

            // Check dominance condition
            if (f1[dominant] * 2 > leftSize && f2[dominant] * 2 > rightSize)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    MinimumIndexofValidSplit_2780 m1;
    std::vector<int> nums = {2, 1, 3, 1, 1, 1, 7, 1, 2, 1};
    std::cout << m1.minimumIndex(nums) << std::endl; // Expected Output: 4
    return 0;
}
