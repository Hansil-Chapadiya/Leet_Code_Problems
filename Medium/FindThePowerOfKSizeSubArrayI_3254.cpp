#include <iostream>
#include <vector>
class FindThePowerOfKSizeSubArrayI_3254
{
private:
    /* data */
public:
    std::vector<int> resultsArray(std::vector<int> &nums, int k)
    {
        std::vector<int> answer;
        for (int i = 0; i < (nums.size() - k + 1); i++)
        {
            bool isContiguous = true;
            for (int j = 1; j < k; j++)
            {
                if (nums[i + j] - nums[i + j - 1] != 1)
                {
                    answer.push_back(-1);
                    isContiguous = false;
                    break;
                }
            }
            if (isContiguous)
            {
                int val = nums[i] + k - 1;
                answer.push_back(val);
            }
        }
        // std::cout<<answer.size();
        return answer;
    }
};
int main()
{
    FindThePowerOfKSizeSubArrayI_3254 f1;
    // std::vector<int> nums = {1, 2, 3, 4, 3, 2, 5};
    // std::vector<int> nums = {2,2,2,2,2};
    std::vector<int> nums = {3,2,3,2,3,2};
    // std::vector<int> answer = f1.resultsArray(nums, 3);
    // std::vector<int> answer = f1.resultsArray(nums, 4);
    std::vector<int> answer = f1.resultsArray(nums, 2);
    for (auto i : answer)
    {
        std::cout << i << " ";
    }

    return 0;
}
