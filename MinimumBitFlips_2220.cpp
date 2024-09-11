#include <iostream>
using namespace std;

// class MinimumBitFlips_2220
// {
// public:
//     int minBitFlips(int start, int goal)
//     {
//         int x_or_value = start ^ goal; // XOR gives the bits that are different
//         int count = 0;

//         // Count the number of 1's in x_or_value
//         while (x_or_value > 0)
//         {
//             count += (x_or_value & 1); // Check if the last bit is 1
//             x_or_value >>= 1;          // Shift right to check the next bit
//         }

//         return count;
//     }
// };

// int main()
// {
//     MinimumBitFlips_2220 m1;
//     int result = m1.minBitFlips(10, 7);
//     cout << "Minimum bit flips: " << result << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

class MinimumBitFlips_2220
{
public:
    int minBitFlips(int start, int goal)
    {
        int x_or_value = start ^ goal; // XOR gives the bits that are different
        int count = 0;

        // Brian Kernighan’s algorithm to count set bits (1s)
        while (x_or_value > 0)
        {
            x_or_value &= (x_or_value - 1); // Turn off the rightmost 1-bit
            // x_or_value = x_or_value & (x_or_value - 1)
            count++;
        }

        return count;
    }
};

int main()
{
    MinimumBitFlips_2220 m1;
    int result = m1.minBitFlips(10, 7);
    cout << "Minimum bit flips: " << result << endl;
    return 0;
}
