#include <iostream>
#include <string>
#include <unordered_set>

class SplitAStringIntoMaxNumberOfSubstring_1593
{
private:
    int backtrack(const std::string &s, std::unordered_set<std::string> &seenSubstrings, int start)
    {
        if (start == s.size())
        {
            // If we've reached the end of the string, return 0 (no more splits possible)
            return 0;
        }

        int maxSplits = 0; // Store the maximum number of splits found

        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= s.size(); ++end)
        {
            std::string substring = s.substr(start, end - start);

            // If this substring has not been seen before, we can "split" here
            if (seenSubstrings.find(substring) == seenSubstrings.end())
            {
                // Add the substring to the set of seen substrings
                seenSubstrings.insert(substring);

                // Recursively find the maximum splits for the remaining part of the string
                maxSplits = std::max(maxSplits, 1 + backtrack(s, seenSubstrings, end));

                // Backtrack: remove the substring from the set of seen substrings
                seenSubstrings.erase(substring);
            }
        }

        return maxSplits;
    }

public:
    int maxUniqueSplit(std::string s)
    {
        std::unordered_set<std::string> seenSubstrings; // To track unique substrings
        return backtrack(s, seenSubstrings, 0);
    }
};

int main()
{
    SplitAStringIntoMaxNumberOfSubstring_1593 s1;
    std::cout << s1.maxUniqueSplit("ababccc") << std::endl; // Expected output: 5 (a, b, ab, c, cc)
    return 0;
}
