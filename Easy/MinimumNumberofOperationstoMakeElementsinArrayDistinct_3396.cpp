/* #include <iostream>
#include <vector>
#include <unordered_map>

class MinimumNumberofOperationstoMakeElementsinArrayDistinct_3396
{
public:
    bool isValid(std::vector<int> arr)
    {
        std::unordered_map<int, int> freqmap;
        for (int i = 0; i < arr.size(); i++)
        {
            freqmap[arr[i]]++;
            if (freqmap[arr[i]] > 1)
            {
                return false;
            }
        }
        return true;
    }
    int minimumOperations(std::vector<int> &nums)
    {
        if (isValid(nums))
        {
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < nums.size(); i += 3)
        {
            std::vector<int> temp;
            for (int j = i; j < nums.size(); j++)
            {
                temp.push_back(nums[j]);
            }
            if (isValid(temp))
            {
                // cnt++;
                return cnt;
            }
            else
            {
                cnt++;
            }
            temp.clear();
        }

        return cnt;
    }
};

int main()
{
    MinimumNumberofOperationstoMakeElementsinArrayDistinct_3396 m1;
    // std::vector<int> nums = {6,7,8,9};
    // std::vector<int> nums = {4,5,6,4,4};
    std::vector<int> nums = {1, 2, 3, 4, 2, 3, 3, 5, 7};
    std::cout << m1.minimumOperations(nums);

    return 0;
} */

#include <iostream>
#include <vector>
#include <unordered_map>

class MinimumNumberofOperationstoMakeElementsinArrayDistinct_3396
{
public:
    bool isValid(std::vector<int> arr)
    {
        std::unordered_map<int, int> freqmap;
        for (int i = 0; i < arr.size(); i++)
        {
            freqmap[arr[i]]++;
            if (freqmap[arr[i]] > 1)
            {
                return false;
            }
        }
        return true;
    }

    int minimumOperations(std::vector<int> &nums)
    {
        int cnt = 0;
        while (!isValid(nums))
        {
            cnt++;
            int removeCount = std::min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
        }
        return cnt;
    }
};

int main()
{
    MinimumNumberofOperationstoMakeElementsinArrayDistinct_3396 m1;
    std::vector<int> nums = {6, 7, 8, 9};
    // std::vector<int> nums = {4, 5, 6, 4, 4};
    // std::vector<int> nums = {1, 2, 3, 4, 2, 3, 3, 5, 7};
    std::cout << m1.minimumOperations(nums) << std::endl;

    return 0;
}
