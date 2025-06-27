/* #include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Permutation
{
public:
    std::vector<std::vector<int>> nextPermutation(std::vector<int> nums)
    {
        std::vector<std::vector<int>> answer;

        std::function<void(int)> allPermutation = [&](int start)
        {
            if (start == nums.size())
            {
                answer.push_back(nums);
                return;
            }

            for (int i = start; i < nums.size(); i++)
            {
                std::swap(nums[start], nums[i]);
                allPermutation(start + 1);
                std::swap(nums[start], nums[i]); // backtrack
            }
        };

        allPermutation(0);
        return answer;
    }
};

int main()
{
    Permutation obj;

    std::vector<int> nums = {2, 1, 3};
    std::vector<std::vector<int>> answer = obj.nextPermutation(nums);

    for (const auto& perm : answer)
    {
        for (int num : perm)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Permutation
{
public:
    void nextPermutation(std::vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 2;

        while(i >=0 && nums[i]>=nums[i+1]) i--;

        if(i>=0)
        {
            int j = n - 1;
            while(nums[j] <= nums[i]) j--;

            std::swap(nums[i], nums[j]);
        }

        std::reverse(nums.begin() + i + 1, nums.end());
    }
};

int main()
{
    Permutation obj;

    std::vector<int> nums = {2, 1, 3};
    obj.nextPermutation(nums);

    for(int n: nums)
    {
        std::cout<<n<<" ";
    }

    return 0;
}
