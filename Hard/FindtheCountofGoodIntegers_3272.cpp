#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>

class FindtheCountofGoodIntegers_3272
{
public:
    long long countPermutations(const std::string &digits)
    {
        int n = digits.size();
        std::unordered_map<char, int> freqMap;
        for (char c : digits)
        {
            freqMap[c]++;
        }

        long long total = 1;
        for (int i = 2; i <= n; i++)
        {
            total *= i;
        }

        for (auto &[ch, count] : freqMap)
        {
            for (int i = 2; i <= count; i++)
            {
                total /= i;
            }
        }

        long long valid = 0;
        for (char c = '1'; c <= '9'; c++)
        {
            if (freqMap[c] == 0)
                continue;

            freqMap[c]--;
            int remaining = n - 1;
            long long permutation = 1;
            for (int i = 2; i <= remaining; i++)
            {
                permutation *= i;
            }

            for (auto &[ch, count] : freqMap)
            {
                for (int i = 2; i <= count; i++)
                {
                    permutation /= i;
                }
            }

            valid += permutation;
            freqMap[c]++;
        }

        return valid;
    }
    long long countGoodIntegers(int n, int k)
    {
        std::unordered_set<std::string> nDigitNumbers;
        int base = std::pow(10, (n - 1) / 2);
        int skip = n & 1;

        for (int i = base; i < base * 10; i++)
        {
            std::string left = std::to_string(i);
            std::string right = left;
            if (skip)
                right.pop_back();
            std::reverse(right.begin(), right.end());
            std::string fullPalindrome = left + right;

            long long num = std::stoll(fullPalindrome);
            if (num % k == 0)
            {
                std::string sorted = fullPalindrome;
                std::sort(sorted.begin(), sorted.end());
                nDigitNumbers.insert(sorted);
            }
        }

        long long result = 0;
        for (const auto &digits : nDigitNumbers)
        {
            result += countPermutations(digits);
        }

        return result;
    }
};

int main()
{
    FindtheCountofGoodIntegers_3272 f1;
    std::cout << f1.countGoodIntegers(3, 5);

    return 0;
}