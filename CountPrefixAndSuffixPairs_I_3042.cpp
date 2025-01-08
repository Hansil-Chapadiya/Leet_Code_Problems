#include <iostream>
#include <vector>
#include <string>
class CountPrefixAndSuffixPairs_I_3042
{
private:
    bool starts_with(std::string s, std::string prefix)
    {
        if (s.length() < prefix.length())
        {
            return false;
        }
        return s.compare(0, prefix.length(), prefix) == 0;
    }
    bool ends_with(std::string s, std::string suffix)
    {
        if (s.length() < suffix.length())
        {
            return false;
        }
        return s.compare(s.length() - suffix.length(), suffix.length(), suffix) == 0;
    }

public:
    int countPrefixSuffixPairs(std::vector<std::string> &words)
    {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (starts_with(words[j], words[i]) && ends_with(words[j], words[i]))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main()
{
    CountPrefixAndSuffixPairs_I_3042 c1;
    std::vector<std::string> words = {"a", "aba", "ababa", "aa"};
    std::cout<<c1.countPrefixSuffixPairs(words);
    return 0;
}
