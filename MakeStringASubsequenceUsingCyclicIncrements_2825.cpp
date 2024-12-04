#include <iostream>
#include <string>

class MakeStringASubsequenceUsingCyclicIncrements_2825
{
private:
    /* data */
public:
    bool canMakeSubsequence(std::string str1, std::string str2)
    {
        int i = 0;
        int j = 0;
        while (i < str1.length() && j < str2.length())
        {
            char c;
            if (str1[i] == 'z')
            {
                c = 'a';
            }
            else
            {
                c = str1[i] + 1;
            }
            if (str1[i] == str2[j] || (c) == str2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (j == str2.length())
        {
            return true;
        }
        return false;
    }
};
int main()
{
    MakeStringASubsequenceUsingCyclicIncrements_2825 m1;
    // std::string str1 = "abc";
    // std::string str2 = "ad";
    std::string str1 = "zc";
    std::string str2 = "ad";
    std::cout << m1.canMakeSubsequence(str1, str2);
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();