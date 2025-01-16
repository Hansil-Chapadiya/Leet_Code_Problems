#include <iostream>
#include <string>
#include <cmath>

class MinimumSwapsToBalance
{
public:
    int minSwaps(std::string s)
    {
        int leftBrackets = 0;  // To count the number of '[' brackets
        int unbalanced = 0;    // To count the number of unbalanced brackets

        // Traverse through the string
        for (char c : s)
        {
            if (c == '[')
                leftBrackets++;  // Increment when we encounter '['
            else
            {
                if (leftBrackets > 0)
                    leftBrackets--;  // Match ']' with a previous unmatched '['
                else
                    unbalanced++;  // Increment unbalanced count if there is no matching '['
            }
        }

        // Each swap fixes 2 unbalanced brackets, so we need unbalanced / 2 swaps
        return std::ceil(unbalanced / 2.0);
    }
};

int main()
{
    MinimumSwapsToBalance m1;
    std::cout << m1.minSwaps("]]][[[") << std::endl;  // Output: 2
    std::cout << m1.minSwaps("[]") << std::endl;      // Output: 0 (Already balanced)
    return 0;
}
