#include <iostream>
#include <string>

class SeperateBlackAndWhiteBalls_2938
{
private:
    // Variable to track the number of swaps
    long long swapCount = 0;

public:
    // Function to sort the characters in the string using Bubble Sort and count swaps
    long long swaps(std::string &s)
    {
        int n = s.length();
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (s[j] > s[j + 1])
                {
                    // Swap characters if they are out of order
                    std::swap(s[j], s[j + 1]);
                    swapCount++; // Increment swap count
                }
            }
        }
        return swapCount;
    }
};

int main()
{
    SeperateBlackAndWhiteBalls_2938 sorter;
    std::string s = "0111";

    long long swapCount = sorter.swaps(s);

    std::cout << "Sorted string: " << s << std::endl;
    std::cout << "Number of swaps: " << swapCount << std::endl;

    return 0;
}
