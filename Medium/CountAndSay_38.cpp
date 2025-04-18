#include <iostream>
#include <string>

class CountAndSay_38
{
public:
    //  Helper to generate the next term in the sequence
    std::string helper(const std::string &s)
    {
        std::string temp = "";
        int i = 0;
        int n = s.length();

        while (i < n)
        {
            char currentChar = s[i];
            int count = 0;

            while (i < n && s[i] == currentChar)
            {
                count++;
                i++;
            }

            temp += std::to_string(count);
            temp += currentChar;
        }

        return temp;
    }

    //  Main function for Leetcode 38
    std::string countAndSay(int n)
    {
        if (n <= 0)
            return "";

        std::string result = "1";

        for (int i = 1; i < n; ++i)
        {
            result = helper(result); // build the next term from current one
        }

        return result;
    }
};

int main()
{
    CountAndSay_38 c1;
    std::cout << c1.countAndSay(5) << std::endl; // Output should be "111221"
    return 0;
}
