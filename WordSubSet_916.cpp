#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
class WordSubSet_916
{
private:
    /* data */
public:
    std::vector<std::string> wordSubsets(std::vector<std::string> &words1, std::vector<std::string> &words2)
    {
    }
};
int main()
{
    std::vector<std::string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    std::vector<std::string> words2 = {"e", "o"};
    WordSubSet_916 w1;
    w1.wordSubsets(words1, words2);
    return 0;
}