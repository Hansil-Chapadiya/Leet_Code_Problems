#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
class PrimeSubtractionOparation_2601
{
private:
    std::vector<int> isPrime;
    // void primeList()
    // {
    //     for (int i = 2; i < 1000; i++)
    //     {
    //         bool isPrime = true;
    //         for (int j = 2; j <= std::sqrt(i); j++)
    //         {
    //             if (i % j == 0)
    //             {
    //                 isPrime = false;
    //                 break;
    //             }
    //         }
    //         if (isPrime)
    //         {
    //             primes.push_back(i);
    //         }
    //     }
    //     // std::cout << primes.size();
    // }

    // Efficient Sieve of Eratosthenes for generating prime numbers up to 1000
    void generatePrimesUpTo(int limit)
    {
        isPrime.resize(limit + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= std::sqrt(limit + 1); i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= limit; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }

public:
    bool primeSubOperation(std::vector<int> &nums)
    {
        int max_element = *std::max_element(nums.begin(), nums.end());
        generatePrimesUpTo(max_element); // Generate primes up to the maximum needed
        int currrent = 1;
        int i = 0;
        while (i < nums.size())
        {
            int difference = nums[i] - currrent;
            if (difference < 0)
            {
                return false;
            }

            if (isPrime[difference] == true || difference == false)
            {
                i++;
                currrent++;
            }
            else
            {
                currrent++;
            }
        }

        return true;
    }
};
int main()
{
    PrimeSubtractionOparation_2601 p1;
    // std::vector<int> nums = {4, 9, 6, 10};
    std::vector<int> nums = {5, 8, 3};
    std::cout << p1.primeSubOperation(nums);
    return 0;
}
