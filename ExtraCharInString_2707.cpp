#include <iostream>
#include <vector>
#include <string>

/*
Overlapping Substrings: The current approach does not account for overlapping dictionary words that might exist within the string. For instance, removing one substring could prevent another substring from being found or could result in incorrect deletion.
*/
class ExtraCharInString_2707
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

int main()
{
    ExtraCharInString_2707 e1;

    // Example 1
    // std::string s = "leetscode";
    // std::vector<std::string> dictionary = {"leet", "code", "leetcode"};

    // Example 2
    // std::string s = "sayhelloworld";
    // std::vector<std::string> dictionary = {"hello", "world"};

    // Example 3
    std::string s = "dwmodizxvvbosxxw";
    std::vector<std::string> dictionary = {"ox", "lb", "diz", "gu", "v", "ksv", "o", "nuq", "r", "txhe", "e", "wmo", "cehy", "tskz", "ds", "kzbu"};

    // Output the remaining length of the string after removing substrings
    std::cout << e1.minExtraChar(s, dictionary) << std::endl;

    return 0;
}
