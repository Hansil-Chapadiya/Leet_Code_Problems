#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
class LongestStringWithoutRepeatingChar_6
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> char_index; // Map stores the last seen index of each character
        int max_len = 0;                          // Variable to store the maximum length of substring
        int start = 0;                            // Left boundary of the sliding window

        for (int i = 0; i < s.length(); ++i)
        {
            char current_char = s[i]; // Current character in the string

            // If the character is already in the map and its last index is within the current window
            if (char_index.find(current_char) != char_index.end() && char_index[current_char] >= start)
            {
                // Move the start pointer to exclude the repeating character
                start = char_index[current_char] + 1;
            }

            // Update or insert the last seen index of the current character
            char_index[current_char] = i;

            // Calculate the length of the current valid substring and update max_len
            max_len = std::max(max_len, i - start + 1);
        }

        return max_len;
    }
};
int main()
{
    LongestStringWithoutRepeatingChar_6 l1;
    // std::cout << l1.lengthOfLongestSubstring("abcabcbb");
    // std::cout << l1.lengthOfLongestSubstring("bbbbb");
    std::cout << l1.lengthOfLongestSubstring("pwwkew");
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();