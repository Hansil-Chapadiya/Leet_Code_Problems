#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FindthePunishmentNumberofanInteger_2698
{
private:
    // Function to check if a square can be split into parts that sum to `num`
    bool canBePartitioned(string s, int num, int sum = 0, int index = 0)
    {
        if (index == s.length())
        {
            return sum == num; // If sum equals num at the end, return true
        }

        int currentSum = 0;
        for (int i = index; i < s.length(); i++)
        {
            currentSum = currentSum * 10 + (s[i] - '0'); // Convert substring to number
            if (canBePartitioned(s, num, sum + currentSum, i + 1))
            {
                return true;
            }
        }

        return false;
    }

public:
    int punishmentNumber(int n)
    {
        int totalSum = 0;
        for (int i = 1; i <= n; i++)
        {
            int squared = i * i;
            string squaredStr = to_string(squared);

            // Check if the squared number can be partitioned
            if (canBePartitioned(squaredStr, i))
            {
                totalSum += squared;
            }
        }
        return totalSum;
    }
};

int main()
{
    FindthePunishmentNumberofanInteger_2698 f1;
    cout << f1.punishmentNumber(10) << endl; // Example test case
    return 0;
}
/*
if (n < 9)
            return 1;
        if (n == 9)
            return 82;
        if (n < 36)
            return 182;
        if (n < 45)
            return 1478;
        if (n < 55)
            return 3503;
        if (n < 82)
            return 6528;
        if (n < 91)
            return 13252;
        if (n < 99)
            return 21533;
        if (n < 100)
            return 31334;
        if (n < 235)
            return 41334;
        if (n < 297)
            return 96559;
        if (n < 369)
            return 184768;
        if (n < 370)
            return 320929;
        if (n < 379)
            return 457829;
        if (n < 414)
            return 601470;
        if (n < 657)
            return 772866;
        if (n < 675)
            return 1204515;
        if (n < 703)
            return 1660140;
        if (n < 756)
            return 2154349;
        if (n < 792)
            return 2725885;
        if (n < 909)
            return 3353149;
        if (n < 918)
            return 4179430;
        if (n < 945)
            return 5022154;
        if (n < 964)
            return 5915179;
        if (n < 990)
            return 6844475;
        if (n < 991)
            return 7824575;
        if (n < 999)
            return 8806656;
        if (n < 1000)
            return 9804657;
        return 10804657;
*/