#include <iostream>
#include <vector>

class FindArrayCanBeSorted_3011
{
private:
    // Function to count the number of set bits in a number
    int countSetBits(int num)
    {
        int count = 0;
        while (num)
        {
            count += (num & 1);
            num >>= 1;
        }
        return count;
    }

public:
    // Function to check if we can sort the array by set bit count
    bool canSortArray(std::vector<int> &nums)
    {
        int n = nums.size();

        // Perform adjacent swaps to achieve sorted order by set bit count and value
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                int count1 = countSetBits(nums[j]);
                int count2 = countSetBits(nums[j + 1]);

                // Swap if adjacent elements have the same set bit count and are out of order
                if (count1 == count2 && nums[j] > nums[j + 1])
                {
                    std::swap(nums[j], nums[j + 1]);
                }
            }
        }

        // Check if the array is now sorted in ascending order
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    std::vector<int> nums = {8, 4, 2, 30, 15};
    FindArrayCanBeSorted_3011 f1;
    std::cout << f1.canSortArray(nums);
    return 0;
}