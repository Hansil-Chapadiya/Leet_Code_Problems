#include <iostream>
#include <string>

class MinimumStringLengthAfterRemovingSubString_2696
{
public:
    // Function to find and remove all "AB" and "CD" substrings iteratively
    int minLength(std::string s)
    {
        // Using a stack to efficiently remove "AB" and "CD" pairs
        std::string result = "";

        for (char ch : s)
        {
            // If the current character forms "AB" or "CD" with the last character in the stack, pop the stack
            if (!result.empty() && ((result.back() == 'A' && ch == 'B') || (result.back() == 'C' && ch == 'D')))
            {
                result.pop_back(); // Remove the pair
            }
            else
            {
                result.push_back(ch); // Add character to the stack
            }
        }

        return result.length(); // The remaining length after removals
    }
};

int main()
{
    MinimumStringLengthAfterRemovingSubString_2696 m1;
    std::cout << m1.minLength("DCDCBCBDACBBABDABABCCCBABCCCCCCCBDDBCDACDADABADDCDBBC") << std::endl;
    return 0;
}

/*
#include <iostream>
#include <string>
class MinimumStringLengthAfterRemovingSubString_2696
{
private:
    std::string removeAB(std::string s)
    {
        while (s.find("AB") != std::string::npos || s.find("CD") != std::string::npos)
        {
            std::string str = "";
            if (int pos = s.find("AB") != std::string::npos)
            {
                if (pos == 1)
                {
                    str += s.substr(2, s.length());
                    s = str;
                }
                else
                {
                    str += s.substr(0, pos);
                    str += s.substr(pos + 1, s.length());
                    s = str;
                    std::cout << s << "\n";
                }
            }
            else if(int pos = s.find("CD") != std::string::npos)
            {
                if (pos == 1)
                {
                    str += s.substr(2, s.length());
                    s = str;
                }
                else
                {
                    str += s.substr(0, pos);
                    str += s.substr(pos + 1, s.length());
                    s = str;
                    std::cout << s << "\n";
                }
            }
        }
        return s;
    }
    std::string removeCD(std::string s)
    {
        while (s.find("CD") != std::string::npos)
        {
            int pos = s.find("CD");
            std::string str = "";
            if (pos == 0)
            {
                str += s.substr(2, s.length());
                s = str;
            }
            else
            {
                str += s.substr(0, pos);
                str += s.substr(pos + 1, s.length());
                s = str;
                std::cout << s << "\n";
            }
        }
    }

public:
    int minLength(std::string s)
    {
        s = removeAB(s);
        return s.length();
    }
};
int main()
{
    MinimumStringLengthAfterRemovingSubString_2696 m1;
    std::cout << m1.minLength("DCDCBCBDACBBABDABABCCCBABCCCCCCCBDDBCDACDADABADDCDBBC");
    return 0;
}


*/