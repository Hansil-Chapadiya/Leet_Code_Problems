#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
class ConstructKPalindromeString_1400
{
private:
    /* data */
public:
    bool canConstruct(std::string s, int k)
    {
        if (s.length() < k)
        {
            return false;
        }

        std::unordered_map<char, int> freq_cnt;
        for (auto c : s)
        {
            freq_cnt[c]++;
        }
        int cnt = 0;
        for (auto c : freq_cnt)
        {
            if (c.second % 2 == 1)
            {
                cnt++;
            }
        }
        return cnt > k ? false : true;
    }
};
int main()
{
    ConstructKPalindromeString_1400 c1;
    std::cout << c1.canConstruct("ab", 10);
    return 0;
}