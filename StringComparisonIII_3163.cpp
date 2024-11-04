#include <iostream>
#include <string>
class StringComparisonIII_3163
{
private:
    /* data */
public:
    std::string compressedString(std::string word)
    {
        if (word.length() == 1)
        {
            return "1" + word;
        }

        std::string comp;
        comp = "";
        int cnt = 1;
        for (int i = 1; i <= word.length(); i++)
        {
            while (word[i] == word[i - 1] && cnt < 9)
            {
                cnt++;
                if (i < word.length())
                {
                    i++;
                }
            }
            comp += std::to_string(cnt);
            comp += word[i - 1];
            cnt = 1;
        }
        return comp;
    }
};
int main()
{
    StringComparisonIII_3163 s1;
    std::string word = "abcde";
    // std::string word = "aaaaaaaaaaaaaabb";
    // std::string word = "o";
    // std::string word = "vvv";
    std::cout << s1.compressedString(word);
    return 0;
}