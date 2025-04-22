#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
/* class Solution {
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
    }(); */

class Solution {
    public:
        int majorityElement(std::vector<int>& nums) {

            std::sort(nums.begin(), nums.end());
            int max = 0;
            int majorityElement = nums[0];
            int condition = nums.size() / 2;

            for (int i = 1; i < nums.size(); i++)
            {
                int cnt = 1;

                while ( i < nums.size() && nums[i - 1] == nums[i])
                {
                    cnt++;
                    i++;
                }

                if(cnt > max && cnt > condition )
                {
                    max = cnt;
                    majorityElement = nums[i-1];
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