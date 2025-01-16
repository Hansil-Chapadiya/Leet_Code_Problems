#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

class FindLongestSpecialSubstringThatOccursThrice
{
public:
    int maximumLength(std::string s)
    {
        std::unordered_map<std::string, int> occurrance_map;

        // Generate all special substrings from every starting position
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            std::string current = "";
            for (int j = i; j < n && s[j] == c; j++)
            {
                current += s[j];           // Create the special substring
                occurrance_map[current]++; // Count its occurrence
            }
        }

        // Find the longest special substring that occurs at least 3 times
        int max_length = 0;
        for (auto map : occurrance_map)
        {
            if (map.second >= 3) // Check if the substring appears at least 3 times
            {
                max_length = std::max(max_length, (int)map.first.length());
            }
        }

        return max_length == 0 ? -1 : max_length;
    }
};

int main()
{
    FindLongestSpecialSubstringThatOccursThrice f1;
    std::cout << "Test 1: " << f1.maximumLength("aaaa") << std::endl;       // Expect 2 ("aa" appears 3 times)
    std::cout << "Test 2: " << f1.maximumLength("abcdef") << std::endl;     // Expect -1 (no substring appears 3 times)
    std::cout << "Test 3: " << f1.maximumLength("abcaba") << std::endl;     // Expect 1 ("a" appears 3 times)
    std::cout << "Test 4: " << f1.maximumLength("aaabbbccc") << std::endl;  // Expect 1 ("a", "b", "c" each appear at least 3 times)
    std::cout << "Test 5: " << f1.maximumLength("aaaaa") << std::endl;      // Expect 3 ("aaa" appears 3 times)
    std::cout << "Test 6: " << f1.maximumLength("aaaaaaaaaa") << std::endl; // Expect 8 ("aaaaaaaa" appears 3 times)
    std::cout << "Test 7: " << f1.maximumLength("aaaaaaaaaaaaccccccccccccccccccccccccccaaaaaaaaaaaa") << std::endl; // Expect 8 ("aaaaaaaa" appears 3 times)
    return 0;
}
