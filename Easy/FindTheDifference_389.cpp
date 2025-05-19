#include <iostream>
#include <string>
#include <unordered_map>

class FindTheDifference_389
{
  public:
    char findTheDifference(std::string s, std::string t) {
        int totalSum = 0;
        for (char c : t) totalSum += c;
        for (char c : s) totalSum -= c;
        return static_cast<char>(totalSum); // Just to be safe with char conversion
    }
};
int main()
{
    FindTheDifference_389 f1;
    std::cout<<f1.findTheDifference("abcd","abcde");
    // std::cout<<f1.findTheDifference("a","aa");
    return 0;
}



/*

char findTheDifference(std::string s, std::string t) {
        std::unordered_map<char, int> uMap;

        // Count characters in s
        for (char c : s) {
            uMap[c]++;
        }

        // Traverse t and find the odd one out
        for (char c : t) {
            uMap[c]--;
            if (uMap[c] < 0) {
                return c; // This char wasn't in s or appeared more in t
            }
        }

        return ' '; // Should never reach here if input is valid
    }

*/