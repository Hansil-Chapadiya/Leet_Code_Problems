/*
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
class ZeroArrayTransformationII
{
public:
    bool isZeroVector(const std::vector<int> &nums)
    {
        return std::all_of(nums.begin(), nums.end(), [](int i)
                           { return i == 0; });
    }
    int minZeroArray(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
    {
        int k = 0;
        for (auto range : queries) // o(q)
        {
            int start = range[0];
            int end = range[1];
            int diffValue = range[2];
            int zeroCount = 0;
            for (int i = start; i <= end; i++) // o(q * r)
            {
                if (nums[i] != 0)
                {
                    nums[i] -= diffValue;
                }
                if (nums[i] <= 0)
                {
                    nums[i] = 0;
                }
            }
            if (isZeroVector(nums)) // o(q * r * n)
            {
                k++;
                return k;
            }
            else
            {
                k++;
            }
        }
        return -1;
    }
};

int main()
{
    ZeroArrayTransformationII z1;
    // std::vector<int> nums = {2,0,2};
    std::vector<int> nums = {4, 3, 2, 1};
    // std::vector<std::vector<int>> queries = {{0,2,1},{0,2,1},{1,1,3}};
    std::vector<std::vector<int>> queries = {{1, 3, 2}, {0, 2, 1}};
    std::cout << z1.minZeroArray(nums, queries);

    return 0;
} */

class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size(), left = 0, right = queries.size();

            // If no combination can make array zero
            if (!canFormZeroArray(nums, queries, right)) return -1;

            // Binary search for the minimum number of queries
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (canFormZeroArray(nums, queries, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            return left;
        }

    private:
        bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
            int n = nums.size();
            vector<int> diff(n + 1, 0);

            // Apply first k queries using difference array
            for (int i = 0; i < k; i++) {
                int start = queries[i][0];
                int end = queries[i][1];
                int value = queries[i][2];

                diff[start] -= value;
                if (end + 1 < n) {
                    diff[end + 1] += value;
                }
            }

            // Apply prefix sum to calculate the final state of nums
            int curr = 0;
            for (int i = 0; i < n; i++) {
                curr += diff[i];
                int newValue = nums[i] + curr;

                // If value becomes negative or zero, set it to zero
                if (newValue < 0) newValue = 0;

                if (newValue != 0) return false;
            }

            return true;
        }
    };
