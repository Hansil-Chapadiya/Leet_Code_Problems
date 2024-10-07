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
    // Helper function to remove all "AB" and "CD" substrings from a given string
    std::string removePatterns(std::string s)
    {
        while (true)
        {
            size_t ab_pos = s.find("AB");
            size_t cd_pos = s.find("CD");

            // If neither "AB" nor "CD" is found, break out of the loop
            if (ab_pos == std::string::npos && cd_pos == std::string::npos)
                break;

            // Remove the first occurrence of "AB" or "CD"
            if (ab_pos != std::string::npos)
                s.erase(ab_pos, 2); // Remove "AB"
            else if (cd_pos != std::string::npos)
                s.erase(cd_pos, 2); // Remove "CD"
        }
        return s;
    }

public:
    int minLength(std::string s)
    {
        // Remove all occurrences of "AB" and "CD"
        s = removePatterns(s);
        return s.length(); // Return the length of the remaining string
    }
};

int main()
{
    MinimumStringLengthAfterRemovingSubString_2696 m1;
    std::cout << m1.minLength("DCDCBCBDACBBABDABABCCCBABCCCCCCCBDDBCDACDADABADDCDBBC") << std::endl;
    return 0;
}


*/