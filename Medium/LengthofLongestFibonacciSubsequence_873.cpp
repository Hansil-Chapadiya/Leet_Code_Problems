#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
class PairHash
{
public:
    template <class t1, class t2>
    std::size_t operator()(const std::pair<t1, t2> &p) const
    {
        return std::hash<t1>()(p.first) ^ (std::hash<t2>()(p.second) << 1);
        // return std::hash<T1>()(p.first) ^ (std::hash<T2>()(p.second) << 1)
    }
};
// class LengthofLongestFibonacciSubsequence_873
// {
// public:
//     int lenLongestFibSubseq(std::vector<int> &arr)
//     {
//         std::unordered_map<int, int> indexMap;
//         int n = arr.size();

//         // Step 1: Store value → index mapping
//         for (int i = 0; i < n; i++)
//         {
//             indexMap[arr[i]] = i;
//         }

//         // Step 2: Use a map to store DP values
//         std::unordered_map<std::string, int> dp;
//         int maxLength = 0;

//         // Step 3: Iterate over all pairs (i, j)
//         for (int j = 0; j < n; j++)
//         {
//             for (int i = 0; i < j; i++)
//             {
//                 int x = arr[j] - arr[i]; // Find arr[k] = arr[j] - arr[i]

//                 // Step 4: Check if x exists and appears before i
//                 if (indexMap.find(x) != indexMap.end() && indexMap[x] < i)
//                 {
//                     int k = indexMap[x]; // Get index of x
//                     std::string key = std::to_string(k) + "," + std::to_string(i);
//                     dp[std::to_string(i) + "," + std::to_string(j)] = dp[key] + 1;
//                     maxLength = std::max(maxLength, dp[std::to_string(i) + "," + std::to_string(j)]);
//                 }
//                 else
//                 {
//                     dp[std::to_string(i) + "," + std::to_string(j)] = 2; // Start new sequence
//                 }
//             }
//         }

//         return maxLength >= 3 ? maxLength : 0; // Return 0 if no sequence found
//     }
// };

// int main()
// {
//     LengthofLongestFibonacciSubsequence_873 l1;
//     std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
//     std::cout << l1.lenLongestFibSubseq(nums) << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <unordered_map>

// class LengthofLongestFibonacciSubsequence_873
// {
// public:
//     // Custom hash function for std::pair<int, int>
//     // struct pair_hash
//     // {
//     //     template <class T1, class T2>
//     //     std::size_t operator()(const std::pair<T1, T2> &p) const
//     //     {
//     //         return std::hash<T1>()(p.first) ^ (std::hash<T2>()(p.second) << 1);
//     //     }
//     // };

//     int lenLongestFibSubseq(std::vector<int> &arr)
//     {
//         std::unordered_map<int, int> indexMap;
//         int n = arr.size();

//         // Step 1: Store value → index mapping
//         for (int i = 0; i < n; i++)
//         {
//             indexMap[arr[i]] = i;
//         }

//         // Step 2: Use an unordered_map with a pair key
//         std::unordered_map<std::pair<int, int>, int, PairHash> dp;
//         int maxLength = 0;

//         // Step 3: Iterate over all pairs (i, j)
//         for (int j = 0; j < n; j++)
//         {
//             for (int i = 0; i < j; i++)
//             {
//                 int x = arr[j] - arr[i]; // Find arr[k] = arr[j] - arr[i]

//                 // Step 4: Check if x exists and appears before i
//                 if (indexMap.find(x) != indexMap.end() && indexMap[x] < i)
//                 {
//                     int k = indexMap[x]; // Get index of x
//                     dp[{i, j}] = dp[{k, i}] + 1;
//                     maxLength = std::max(maxLength, dp[{i, j}]);
//                 }
//                 else
//                 {
//                     dp[{i, j}] = 2; // Start new sequence
//                 }
//             }
//         }

//         return maxLength >= 3 ? maxLength : 0; // Return 0 if no sequence found
//     }
// };

// int main()
// {
//     LengthofLongestFibonacciSubsequence_873 l1;
//     std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
//     std::cout << l1.lenLongestFibSubseq(nums) << std::endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <unordered_map>

class LengthofLongestFibonacciSubsequence_873
{
public:
    int lenLongestFibSubseq(std::vector<int> &arr)
    {
        int n = arr.size();
        std::unordered_map<int, int> indexMap;
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 2)); // Initialize DP table with 2
        int maxLength = 0;

        // Step 1: Store value → index mapping
        for (int i = 0; i < n; i++)
        {
            indexMap[arr[i]] = i;
        }

        // Step 2: Iterate over all pairs (i, j)
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                int x = arr[j] - arr[i]; // Find arr[k] = arr[j] - arr[i]

                // Step 3: Check if x exists and appears before i
                if (indexMap.find(x) != indexMap.end() && indexMap[x] < i)
                {
                    int k = indexMap[x]; // Get index of x
                    dp[i][j] = dp[k][i] + 1; // Extend previous sequence
                    maxLength = std::max(maxLength, dp[i][j]);
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
