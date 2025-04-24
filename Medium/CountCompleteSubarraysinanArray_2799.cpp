#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class CountCompleteSubarraysinanArray_2799 {
public:
    int countCompleteSubarrays(std::vector<int>& nums) {
        std::unordered_set<int> distinctElements(nums.begin(), nums.end());
        int k = distinctElements.size();
        int n = nums.size();
        int cnt = 0;

        std::unordered_map<int, int> freqMap;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            freqMap[nums[right]]++;

            while (freqMap.size() == k) {
                cnt += n - right; // All subarrays starting at left, ending at right, right+1, ..., n-1 are valid
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0) {
                    freqMap.erase(nums[left]);
                }
                left++;
            }
        }

        return cnt;
    }
};

int main() {
    CountCompleteSubarraysinanArray_2799 c1;

    std::vector<int> nums = {1, 3, 1, 2, 2};
    std::cout << c1.countCompleteSubarrays(nums) << std::endl; // Expected output: 4

    return 0;
}