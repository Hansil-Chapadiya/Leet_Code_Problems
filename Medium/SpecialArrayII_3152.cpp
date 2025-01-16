#include <iostream>
#include <vector>

class SpecialArrayII_3152
{
public:
    // Function to check if the subarrays are special
    std::vector<bool> isArraySpecial(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
    {
        int n = nums.size();

        // Step 1: Create parityChange array
        std::vector<int> parityChange(n - 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            // If adjacent elements have different parity, set parityChange[i] = 1, else 0
            parityChange[i] = (nums[i] % 2 != nums[i + 1] % 2) ? 1 : 0;
        }

        // Step 2: Create prefix sum array for parityChange
        std::vector<int> parityPrefix(n, 0);
        for (int i = 1; i < n; i++)
        {
            parityPrefix[i] = parityPrefix[i - 1] + parityChange[i - 1];
        }

        // Step 3: Answer the queries
        std::vector<bool> special;
        for (auto &q : queries)
        {
            int from = q[0], to = q[1];

            // If from == to, subarray has only one element, so it is automatically "special"
            if (from == to)
            {
                special.push_back(true);
            }
            else
            {
                // Calculate total number of parity changes in the subarray [from, to]
                int totalChanges = parityPrefix[to] - parityPrefix[from];

                // If total changes is exactly (to - from), then it is "special"
                special.push_back(totalChanges == (to - from));
            }
        }

        return special;
    }
};

int main()
{
    std::vector<int> nums = {4, 3, 1, 6};
    std::vector<std::vector<int>> queries = {{0, 2}, {2, 3}};
    SpecialArrayII_3152 s1;
    std::vector<bool> special = s1.isArraySpecial(nums, queries);
    for (bool val : special)
    {
        std::cout << (val ? "true" : "false") << " ";
    }
    return 0;
}
