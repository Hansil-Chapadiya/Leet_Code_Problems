#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
class LengthofLongestFibonacciSubsequence_873
{
public:
    int lenLongestFibSubseq(std::vector<int> &arr)
    {
        std::unordered_map<int, int> indexMap;
        int n = arr.size();

        // Step 1: Store value → index mapping
        for (int i = 0; i < n; i++)
        {
            indexMap[arr[i]] = i;
        }

        // Step 2: Use a map to store DP values
        std::unordered_map<std::string, int> dp;
        int maxLength = 0;

        // Step 3: Iterate over all pairs (i, j)
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                int x = arr[j] - arr[i]; // Find arr[k] = arr[j] - arr[i]

                // Step 4: Check if x exists and appears before i
                if (indexMap.find(x) != indexMap.end() && indexMap[x] < i)
                {
                    int k = indexMap[x]; // Get index of x
                    std::string key = std::to_string(k) + "," + std::to_string(i);
                    dp[std::to_string(i) + "," + std::to_string(j)] = dp[key] + 1;
                    maxLength = std::max(maxLength, dp[std::to_string(i) + "," + std::to_string(j)]);
                }
                else
                {
                    dp[std::to_string(i) + "," + std::to_string(j)] = 2; // Start new sequence
                }
            }
        }

        return maxLength >= 3 ? maxLength : 0; // Return 0 if no sequence found
    }
};

int main()
{
    LengthofLongestFibonacciSubsequence_873 l1;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << l1.lenLongestFibSubseq(nums) << std::endl;
    return 0;
}
