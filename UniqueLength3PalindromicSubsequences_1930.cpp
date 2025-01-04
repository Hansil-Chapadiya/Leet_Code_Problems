/* #include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class UniqueLength3PalindromicSubsequences_1930
{
private:
    int len;
    std::string s;
    std::unordered_set<std::string> uniqueSubsequences;

    // Check if a string is palindromic
    bool isPalin(const std::string &str)
    {
        return str[0] == str[2]; // Only length-3 strings, so we check first and last characters
    }

    // Generate subsequences
    void findsubsequences(int index, std::string currentSubsequence)
    {
        // Base case: If subsequence length is 3, process it
        if (currentSubsequence.length() == 3)
        {
            if (isPalin(currentSubsequence))
            {
                uniqueSubsequences.insert(currentSubsequence);
            }
            return;
        }

        // If we've considered all characters, stop
        if (index == len)
        {
            return;
        }

        // Include the current character
        findsubsequences(index + 1, currentSubsequence + s[index]);

        // Exclude the current character
        findsubsequences(index + 1, currentSubsequence);
    }

public:
    int countPalindromicSubsequence(std::string s)
    {
        this->s = s;
        this->len = s.length();
        findsubsequences(0, "");          // Start recursive function
        return uniqueSubsequences.size(); // Return the number of unique palindromic subsequences
    }
};

int main()
{
    UniqueLength3PalindromicSubsequences_1930 u1;
    std::cout << u1.countPalindromicSubsequence("aabca") << std::endl; // Expected output: 3
    return 0;
}
 */

#include <iostream>
#include <string>
#include <unordered_set>

class UniqueLength3PalindromicSubsequences_1930
{
public:
    int countPalindromicSubsequence(std::string s)
    {
        int n = s.length();
        std::unordered_set<std::string> uniquePalindromes;

        // Iterate over all possible middle characters
        for (int i = 1; i < n - 1; ++i)
        {
            char middle = s[i];
            std::unordered_set<char> leftSeen, rightSeen;

            // Collect characters to the left of `i`
            for (int j = 0; j < i; ++j)
            {
                leftSeen.insert(s[j]);
            }

            // Collect characters to the right of `i`
            for (int j = i + 1; j < n; ++j)
            {
                rightSeen.insert(s[j]);
            }

            // Form palindromes with `middle` as the center
            for (char left : leftSeen)
            {
                if (rightSeen.count(left))
                {
                    uniquePalindromes.insert(std::string(1, left) + middle + left);
                }
            }
        }

        return uniquePalindromes.size();
    }
};

int main()
{
    UniqueLength3PalindromicSubsequences_1930 u1;
    std::cout << u1.countPalindromicSubsequence("aabca") << std::endl; // Expected output: 3 ("aba", "aaa", "aca")
    return 0;
}
