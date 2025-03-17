#include <iostream>
#include <vector>
#include <unordered_map>

class DivideArrayIntoEqualPairs_2206
{
public:
    std::unordered_map<int, int> freqMap;
    bool divideArray(std::vector<int> &nums)
    {
        if (nums.size() % 2 != 0)
            return false;

        for (int i : nums)
        {
            freqMap[i]++;
        }

        for (auto i : freqMap)
        {
            if (i.second % 2 != 0)
                return false;
        }
        return true;
    }
};
int main()
{

    DivideArrayIntoEqualPairs_2206 d1;
    // std::vector<int> nums = {3,2,3,2,2,2};
    std::vector<int> nums = {1, 2, 3, 4};
    std::cout << d1.divideArray(nums);
    return 0;
}