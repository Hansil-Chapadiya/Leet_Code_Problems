#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
class CountVowelInStringRange_2559
{
private:
    /* data */
public:
    std::vector<int> vowelStrings(std::vector<std::string> &words, std::vector<std::vector<int>> &queries)
    {
    }
};
int main()
{
    std::vector<std::string> words = {"apple", "orange", "banana", "umbrella", "egg", "iguana", "onion"};
    std::vector<std::vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
    CountVowelInStringRange_2559 c1;
    std::vector<int> answer = c1.vowelStrings(words, queries);
    for (auto i : answer)
    {
        std::cout << i << " ";
    }
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();