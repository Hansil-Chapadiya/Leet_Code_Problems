/* #include <iostream>
#include <vector>
#include <algorithm>

class ContainDuplicate_217
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    // std::vector<int> nums = {1,2,3,1};
    std::vector<int> nums = {1, 2, 3, 4};

    ContainDuplicate_217 c1;
    std::cout << c1.containsDuplicate(nums);

    return 0;
} */


/* #include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class ContainDuplicate_217
{
  public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::unordered_map<int,int> uMap;

        for (int i = 0; i < nums.size(); i++)
        {
            uMap[nums[i]]++;

            if(uMap[nums[i]] >= 2)
            {
                return true;
            }
        }

        return false;
    }

};


int main()
{
    // std::vector<int> nums = {1,2,3,1};
    std::vector<int> nums = {1,2,3,4};

    ContainDuplicate_217 c1;
    std::cout<<c1.containsDuplicate(nums);

    return 0;
} */


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

class ContainDuplicate_217
{
  public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::unordered_set<int> uSet;

        for (int i = 0; i < nums.size(); i++)
        {
            if(uSet.count(nums[i]))
            {
                return true;
            }

            uSet.insert(nums[i]);
        }

        return false;
    }

};


int main()
{
    std::vector<int> nums = {1,2,3,1};
    // std::vector<int> nums = {1,2,3,4};

    ContainDuplicate_217 c1;
    std::cout<<c1.containsDuplicate(nums);

    return 0;
}