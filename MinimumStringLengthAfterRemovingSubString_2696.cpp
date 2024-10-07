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
