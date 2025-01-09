#include <iostream>
#include <vector>
#include <set>
class RemoveDuplicateFromArray_26
{
private:
    /* data */
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        /* int c = 0;
        if (nums.size() == 0)
        {
            return 0;
        }
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[c] != nums[i])
            {
                c++;
                nums[c] = nums[i];
            }
        }
        return c + 1; */
        int c = 0;
        if (nums.size() == 0)
        {
            return 0;
        }
        std::set<int> expectednum;
        for (int i = 0; i < nums.size(); i++)
        {
            expectednum.insert(nums[i]);
        }
        nums = std::vector<int>(expectednum.begin(), expectednum.end());
        return expectednum.size();
    }
};
int main()
{
    std::vector<int> nums = {1, 1, 2};
    RemoveDuplicateFromArray_26 r1;
    int k = r1.removeDuplicates(nums);
    std::cout << k;
    return 0;
}