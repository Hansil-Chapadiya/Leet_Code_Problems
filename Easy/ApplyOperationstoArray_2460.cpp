/* #include <iostream>
#include <vector>
class ApplyOperationstoArray_2460
{
public:
    std::vector<int> applyOperations(std::vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                nums[i - 1] *= 2;
                nums[i] = 0;
            }
        }

        std::vector<int> result;
        int cnt = 0;
        for (auto i : nums)
        {
            if (i != 0)
            {
                result.push_back(i);
            }
            else
            {
                cnt++;
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            result.push_back(0);
        }

        return result;
    }
};
int main()
{
    ApplyOperationstoArray_2460 a1;
    std::vector<int> nums = {1, 2, 2, 1, 1, 0};
    // std::vector<int> nums = {0, 1};

    std::vector<int> answer = a1.applyOperations(nums);
    for (auto i : answer)
    {
        std::cout << i << " ";
    }
    return 0;
} */


#include <iostream>
#include <vector>

class ApplyOperationstoArray_2460
{
public:
    std::vector<int> applyOperations(std::vector<int> &nums)
    {
        // Step 1: Apply the operations
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                nums[i - 1] *= 2;
                nums[i] = 0;
            }
        }

        // Step 2: Move all non-zero numbers forward
        int cnt = 0; // Count of non-zero elements
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[cnt++] = nums[i];
            }
        }

        // Step 3: Fill the remaining elements with zeroes
        for (int i = cnt; i < nums.size(); i++)
        {
            nums[i] = 0; // FIXED: removed `i++`
        }

        return nums;
    }
};

int main()
{
    ApplyOperationstoArray_2460 a1;
    std::vector<int> nums = {1, 2, 2, 1, 1, 0};

    std::vector<int> answer = a1.applyOperations(nums);
    for (auto i : answer)
    {
        std::cout << i << " ";
    }
    return 0;
}
