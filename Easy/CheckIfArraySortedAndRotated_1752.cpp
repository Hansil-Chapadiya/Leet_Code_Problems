#include <iostream>
#include <vector>
#include <algorithm>
class CheckIfArraySortedAndRotated_1752
{
public:
    bool check(std::vector<int> &nums)
    {
        std::vector<int> sorted(nums.begin(), nums.end());
        std::sort(sorted.begin(), sorted.end());
        if (nums == sorted)
        {
            return true;
        }

        int rotation_point = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i-1] > nums[i])
            {
                rotation_point++;
            }
            if (rotation_point > 1)
            {
                return false;
            }
        }
        if (rotation_point == 1)
        {
            if (nums[0] >= nums[nums.size() - 1])
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    CheckIfArraySortedAndRotated_1752 c1;
    // std::vector<int> nums = {3, 4, 5, 1, 2};
    // std::vector<int> nums = {2,1,3,4};
    // std::vector<int> nums = {1,2,3};
    std::vector<int> nums = {6,10,6};
    std::cout << c1.check(nums);
    return 0;
}
