#include <iostream>
#include <string>
class CircularSentences_2490
{
private:
    /* data */
public:
    bool isCircularSentence(std::string sentence)
    {
        bool flag = 1;
        if (sentence[0] != sentence[sentence.length() - 1])
        {
            return false;
        }

        for (int i = 1; i < sentence.length(); i++)
        {
            if (sentence[i] == ' ')
            {
                if (sentence[i + 1] != '\0')
                {
                    if (sentence[i - 1] != sentence[i + 1])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        return flag ? true : false;

    }
};
int main()
{
    CircularSentences_2490 c1;
    // std::cout << c1.isCircularSentence("leetcode exercises sound delightful");
    // std::cout << c1.isCircularSentence("a b c d e a");
    // std::cout << c1.isCircularSentence("leetcode Exercises sound delightful");
    std::cout << c1.isCircularSentence("IuTiUtGGsNydmacGduehPPGksKQyT TmOraUbCcQdnZUCpGCYtGp p pG GCcRvZDRawqGKOiBSLwjIDOjdhnHiisfddYoeHqxOqkUvOEyI");
    // std::cout << c1.isCircularSentence("eetcode");
    // std::cout << c1.isCircularSentence("Leetcode is cool");
    return 0;
}