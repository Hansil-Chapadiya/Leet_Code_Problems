#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

/*
Overlapping Substrings: The current approach does not account for overlapping dictionary words that might exist within the string. For instance, removing one substring could prevent another substring from being found or could result in incorrect deletion.
*/
class ExtraCharInString_2707_wrong
{
public:
    int minExtraChar(std::string s, std::vector<std::string> &dictionary)
    {
        // Iterate through each word in the dictionary
        for (int i = 0; i < dictionary.size(); i++)
        {
            size_t position = s.find(dictionary[i]);
            // Keep removing occurrences of the current dictionary word
            while (position != std::string::npos)
            {
                // Remove the found substring
                s.erase(position, dictionary[i].length());
                // Look for the next occurrence of the same substring
                position = s.find(dictionary[i]);
            }
        }
        // Return the remaining length of the string
        return s.length();
    }
};

// int main()
// {
//     ExtraCharInString_2707_wrong e1;

//     // Example 1
//     // std::string s = "leetscode";
//     // std::vector<std::string> dictionary = {"leet", "code", "leetcode"};

//     // Example 2
//     // std::string s = "sayhelloworld";
//     // std::vector<std::string> dictionary = {"hello", "world"};

//     // Example 3
//     std::string s = "dwmodizxvvbosxxw";
//     std::vector<std::string> dictionary = {"ox", "lb", "diz", "gu", "v", "ksv", "o", "nuq", "r", "txhe", "e", "wmo", "cehy", "tskz", "ds", "kzbu"};

//     // Output the remaining length of the string after removing substrings
//     std::cout << e1.minExtraChar(s, dictionary) << std::endl;

//     return 0;
// }

// ###########################################################################################################
/* Using dynamic programming */
class ExtraCharInString_2707
{
public:
    int minExtraChar(std::string s, std::vector<std::string> &dictionary)
    {
        int n = s.size();
        // Initialize dp array where dp[i] is the min extra chars up to position i
        std::vector<int> dp(n + 1, n); // Max length for each position is n (worst case, no removal)
        dp[0] = 0;                     // No characters in the empty prefix

        // Convert dictionary to a set for fast look-up
        std::set<std::string> dict(dictionary.begin(), dictionary.end());

        // Loop through each position in the string
        for (int i = 1; i <= n; i++)
        {
            // Start assuming we are not removing any substrings
            dp[i] = dp[i - 1] + 1;

            // Check for all substrings ending at i
            for (int j = i; j >= 1; j--)
            {
                // Extract substring s[j-1:i]
                std::string sub = s.substr(j - 1, i - j + 1);

                // If it's in the dictionary, minimize the extra characters
                if (dict.find(sub) != dict.end())
                {
                    dp[i] = std::min(dp[i], dp[j - 1]);
                }
            }
        }

        // The result is the minimum extra characters left in the entire string
        return dp[n];
    }
};

int main()
{
    ExtraCharInString_2707 e1;

    // Test case
    std::string s = "dwmodizxvvbosxxw";
    std::vector<std::string> dictionary = {"ox", "lb", "diz", "gu", "v", "ksv", "o", "nuq", "r", "txhe", "e", "wmo", "cehy", "tskz", "ds", "kzbu"};

    // Output the result
    std::cout << e1.minExtraChar(s, dictionary) << std::endl;

    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();