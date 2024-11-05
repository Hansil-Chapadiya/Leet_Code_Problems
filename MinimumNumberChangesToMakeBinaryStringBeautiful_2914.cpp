#include <iostream>
#include <string>
class MinimumNumberChangesToMakeBinaryStringBeautiful_2914
{
private:
    /* data */
public:
    int cnt = 0;
    int minChanges(std::string s)
    {
        for (int i = 1; i < s.length(); i++)
        {
            if (i % 2 != 0)
            {
                if (s[i] != s[i - 1])
                {
                    cnt++;
                    s[i] = s[i - 1];
                }
            }
        }
        return cnt;
    }
};
int main()
{
    MinimumNumberChangesToMakeBinaryStringBeautiful_2914 m1;
    // std::cout << m1.minChanges("111101101110");
    // std::cout << m1.minChanges("000011000000");
    // std::cout << m1.minChanges("0000");
    // std::cout << m1.minChanges("10");
    std::cout << m1.minChanges("1001");
    return 0;
}
