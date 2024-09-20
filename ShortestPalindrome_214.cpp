// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class ShortestPalindrome_214
// {
// private:
//     // Helper function to check if a string is a palindrome
//     bool isPalindrome(const string &s, int start, int end)
//     {
//         while (start < end)
//         {
//             if (s[start] != s[end])
//             {
//                 return false;
//             }
//             start++;
//             end--;
//         }
//         return true;
//     }

// public:
//     string shortestPalindrome(const string s)
//     {
//         int n = s.size();

//         // Find the longest palindromic prefix
//         int longestPalindromicPrefixLength = 0;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (isPalindrome(s, 0, i))
//             {
//                 longestPalindromicPrefixLength = i + 1;
//                 break;
//             }
//         }

//         // The part after the longest palindromic prefix
//         string suffix = s.substr(longestPalindromicPrefixLength);

//         // Reverse the suffix and add it to the front
//         string reversedSuffix = suffix;
//         reverse(reversedSuffix.begin(), reversedSuffix.end());

//         // Construct the shortest palindrome by adding reversed suffix to the front
//         return reversedSuffix + s;
//     }
// };

// int main()
// {
//     ShortestPalindrome_214 s1;
//     cout << s1.shortestPalindrome("aabba") << endl; // Expected: "abbaabba"
//     cout << s1.shortestPalindrome("abcd") << endl; // Expected: "abbaabba"
//     cout << s1.shortestPalindrome("aacecaaa") << endl; // Expected: "abbaabba"
//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class ShortestPalindrome_214
{
public:
    string shortestPalindrome(const string s)
    {
        if (s.empty())
            return s;

        // Create a new string with the original string and its reverse
        string combined = s + "#" + string(s.rbegin(), s.rend());
        int n = combined.size();

        // Create the KMP table
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++)
        {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j])
            {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j])
            {
                j++;
            }
            lps[i] = j;
        }

        // The length of the longest palindromic prefix in the original string
        int longestPalindromicPrefixLength = lps.back();

        // The part after the longest palindromic prefix
        string suffix = s.substr(longestPalindromicPrefixLength);

        // Reverse the suffix and add it to the front
        string reversedSuffix = suffix;
        reverse(reversedSuffix.begin(), reversedSuffix.end());

        // Construct the shortest palindrome
        return reversedSuffix + s;
    }
};

int main()
{
    ShortestPalindrome_214 s1;
    cout << s1.shortestPalindrome("aabba") << endl;    // Expected: "abbaabba"
    cout << s1.shortestPalindrome("abcd") << endl;     // Expected: "dcbabcd"
    cout << s1.shortestPalindrome("aacecaaa") << endl; // Expected: "aaacecaaa"

    return 0;
}

static const int hansil = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();