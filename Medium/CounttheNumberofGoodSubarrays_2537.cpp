#include <iostream>
#include <vector>
#include <unordered_map>

class CounttheNumberofGoodSubarrays_2537 {
public:
    long long countGood(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> numCounter;

        int n = nums.size();
        int left = 0;
        long long matchedPair = 0;
        long long answer = 0;

        for (int right = 0; right < n; ++right) {
            // Count how many pairs this number adds
            matchedPair += numCounter[nums[right]];
            numCounter[nums[right]]++;

            // Shrink from left while we have enough pairs
            while (matchedPair >= k) {
                answer += n - right;
                numCounter[nums[left]]--;
                matchedPair -= numCounter[nums[left]];
                left++;
            }
        }

        return answer;
    }
};

int main() {
    CounttheNumberofGoodSubarrays_2537 c1;
    std::vector<int> nums = {1, 1, 1, 1, 1};
    std::cout << c1.countGood(nums, 10) << std::endl;
    return 0;
}
