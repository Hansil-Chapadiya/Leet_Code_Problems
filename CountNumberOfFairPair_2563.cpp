#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
class CountNumberOfFairPair_2563
{
private:
    /* data */
public:
    long long countFairPairs(std::vector<int> &nums, int lower, int upper)
    {
        // Step 1: Remove duplicates from nums
        std::sort(nums.begin(), nums.end());
        // auto it = std::unique(nums.begin(), nums.end());
        // nums.erase(it, nums.end());

        // Step 2: Use a set to store unique pairs
        // std::set<std::pair<int, int>> pairs;

        // // Lambda function to insert pairs in (min, max) order
        // auto insert_pair = [&](int a, int b)
        // {
        //     // if (a > b)
        //     // {
        //     //     std::swap(a, b);
        //     // }
        //     pairs.insert({a, b});
        // };
        long long cnt =0;
        // Step 3: Iterate over unique pairs
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            { // Start j from i + 1 to avoid duplicates
                int sum = nums[i] + nums[j];
                if (lower <= sum && sum <= upper)
                {
                    // insert_pair(nums[i], nums[j]);
                    cnt++;
                }
            }
        }

        // Return the count of unique pairs
        // return pairs.size();
        return cnt;
    }
};
int main()
{
    CountNumberOfFairPair_2563 c1;
    std::vector<int> nums = {0, 1, 7, 4, 4, 5}; // 0,1,4,5,7
    std::cout << c1.countFairPairs(nums, 3, 6);
    return 0;
}