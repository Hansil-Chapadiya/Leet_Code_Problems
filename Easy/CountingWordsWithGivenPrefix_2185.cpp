#include <iostream>
#include <vector>
#include <string>
class CountingWordsWithGivenPrefix_2185
{
private:
    /* data */
public:
    int prefixCount(std::vector<std::string> &words, std::string pref)
    {
        int cnt = 0;
        for (auto word : words)
        {
            if (word.compare(0, pref.length(), pref) == 0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    CountingWordsWithGivenPrefix_2185 c1;
    std::vector<std::string> words = {"pay", "attention", "practice", "attend"};
    std::cout << c1.prefixCount(words, "at");
    return 0;
}
