#include <iostream>
#include <vector>
#include <string>
class DeleteCharactersToMakeFancyString_1957
{
private:
    /* data */
public:
    std::string makeFancyString(std::string s)
    {
        if (s.empty())
            return "";

        std::string temp;
        int cnt = 1;
        temp += s[0]; // Start with the first character

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
            {
                // Increment the count if the current char is the same as the previous
                if (cnt < 2)
                {
                    temp += s[i];
                    cnt++;
                }
                // If cnt >= 2, skip adding the character
            }
            else
            {
                // Reset count and add the new character
                temp += s[i];
                cnt = 1;
            }
        }

        return temp;
    }
};
int main()
{
    DeleteCharactersToMakeFancyString_1957 d1;
    std::cout << d1.makeFancyString("aaabaaaa");
    // std::cout << d1.makeFancyString("leeetcode");
    return 0;
}