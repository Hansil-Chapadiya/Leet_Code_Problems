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