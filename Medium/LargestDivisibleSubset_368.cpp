#include <iostream>
#include <vector>
#include <algorithm>

class LargestDivisibleSubset_368
{
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        if (nums.empty()) return {};

        std::sort(nums.begin(), nums.end());  // Step 1: Sort
        int n = nums.size();
        std::vector<int> dp(n, 1);            // Step 2: DP array
        std::vector<int> prev(n, -1);         // Step 3: Previous index tracker

        int maxIndx = 0; // To track index of the largest subset

        // Step 4: Fill dp and prev
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > dp[maxIndx]) {
                maxIndx = i;
            }
        }

        // Step 5: Reconstruct the answer
        std::vector<int> answer;
        while (maxIndx != -1) {
            answer.push_back(nums[maxIndx]);
            maxIndx = prev[maxIndx];
        }

        std::reverse(answer.begin(), answer.end());  // Optional: for increasing order
        return answer;
    }
};

int main()
{
    LargestDivisibleSubset_368 l1;
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> answer = l1.largestDivisibleSubset(nums);

    std::cout << "Largest Divisible Subset: ";
    for (auto i : answer) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
