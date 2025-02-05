#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
class CheckifOneStringSwapCanMakeStringsEqual_1790
{
private:
    std::unordered_map<char, int> set_mismatchchar;

public:
    bool areAlmostEqual(std::string s1, std::string s2)
    {
        if (s1.size() != s2.size())
        {
            return false;
        }
        if (s1.size() <= 2)
        {
            return false;
        }
        if (s1 == s2)
        {
            return true;
        }

        int mismatch = 2;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                mismatch--;
                if (mismatch < 0)
                {
                    return false;
                }
                set_mismatchchar[s1[i]]++;
                set_mismatchchar[s2[i]]++;
            }
        }
        for (auto c : set_mismatchchar)
        {
            if ((s1.find(c.first) == std::string::npos) || (s2.find(c.first) == std::string::npos))
            {
                return false;
            }

            if (c.second != 2)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    CheckifOneStringSwapCanMakeStringsEqual_1790 c1;
    std::cout << c1.areAlmostEqual("bank", "kanb");
    // std::cout << c1.areAlmostEqual("attack", "defend");
    // std::cout << c1.areAlmostEqual("kelb", "kelb");
}
