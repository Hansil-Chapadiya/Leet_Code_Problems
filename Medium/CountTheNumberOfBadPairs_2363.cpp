#include <iostream>
#include <vector>
#include <unordered_map>
class CountTheNumberOfBadPairs_2363
{
private:
    std::unordered_map<long long, long long> map;

public:
    long long countBadPairs(std::vector<int> &nums)
    {
        long long good_pairs = 0;
        long long total_pairs = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (i < j && ((j - i) == (nums[j] - nums[i])))
        //         {
        //             good_pairs++;
        //         }
        //         total_pairs++;
        //     }
        // }
        // std::cout << total_pairs << " ";
        // return total_pairs - good_pairs;

        int n = nums.size();
        long long total_pairs = (1LL * n * (n - 1)) / 2; // Total pairs in the array
        long long good_pairs = 0;

        for (int i = 0; i < n; i++)
        {
            int key = nums[i] - i;
            good_pairs += map[key]; // Every occurrence contributes to good pairs
            map[key]++;             // Update
        }

        return total_pairs - good_pairs; // Bad pairs = Total pairs - Good pairs
    }
};
int main()
{
    CountTheNumberOfBadPairs_2363 c1;
    std::vector<int> nums = {4, 1, 3, 3};
    std::cout << c1.countBadPairs(nums);
    return 0;
}