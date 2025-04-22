#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
class Solution {
    public:
        int majorityElement(std::vector<int>& nums) {

            std::unordered_map<int, int> freqCnt;

            int n = nums.size();
            int cnt = n  / 2;
            int majorityElement = 0;
            int majorityCount = 0;

            for (int i = 0; i < n; i++)
            {
                freqCnt[nums[i]]++;
            }

            for(const auto& entry : freqCnt)
            {
                if(entry.second > cnt && entry.second > majorityCount )
                {
                    majorityElement = entry.first;
                    majorityCount = entry.second;
                }
            }
            return majorityElement;

        }
    };
    static const int hansil = []()
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        return 0;
    }();