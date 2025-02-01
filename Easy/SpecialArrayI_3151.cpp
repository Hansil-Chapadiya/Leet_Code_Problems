#include <iostream>
#include <vector>
class SpecialArrayI_3151
{
private:
    bool isOdd(int n1)
    {
        if (n1 % 2 == 1)
        {
            return 1;
        }
        return -1;
    }

public:
    bool isArraySpecial(std::vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return true;
        }

        for (int i = 1; i < nums.size(); i++)
        {
            if (isOdd(nums[i]) == isOdd(nums[i - 1]))
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    SpecialArrayI_3151 s1;
    // std::vector<int> nums = {1};
    // std::vector<int> nums = {2,1,4};
    // std::vector<int> nums = {4, 3, 1, 6};
    std::vector<int> nums = {2,10};
    std::cout << s1.isArraySpecial(nums);
}