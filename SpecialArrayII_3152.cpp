#include <iostream>
#include <vector>
class SpecialArrayII_3152
{
private:
    /* data */
public:
    std::vector<bool> isArraySpecial(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
    {
        std::vector<bool> special;
        for (auto q : queries)
        {
            int flag = 1;
            for (int i = q[0]; i < q[1]; i++)
            {
                // if ((i + 1) != (q[1]+1))
                {
                    if ((nums[i + 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i + 1] % 2 == 1 && nums[i] % 2 == 1))
                    {
                        // special.push_back(false);
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag)
            {
                special.push_back(true);
            }
            else
            {
                special.push_back(false);
            }
        }
        return special;
    }
};
int main()
{
    // std::vector<int> nums = {3, 4, 1, 2, 6};
    std::vector<int> nums = {4, 3, 1, 6};
    // std::vector<std::vector<int>> queries = {{0, 4}};
    std::vector<std::vector<int>> queries = {{0, 2}, {2, 3}};
    SpecialArrayII_3152 s1;
    std::vector<bool> special = s1.isArraySpecial(nums, queries);
    for (int i = 0; i < special.size(); i++)
    {
        std::cout << special[i] << " ";
    }

    return 0;
}