/* #include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
class ClosestPrimeNumbersInRange
{
public:
    std::set<int> primes;
    bool isPrime(int n)
    {
        for (int j = 2; j < n; j++)
        {
            if (n % j == 0)
                return false;
        }
        return true;
    }
    std::vector<int> closestPrimes(int left, int right)
    {
        if (left == 1)
            left++;
        if (right == 1)
            return {-1, -1};
        if (left == right)
            return {-1, -1};
        if (right < left)
            return {-1, -1};
        for (int i = left; i <= right; i++)
        {
            if (isPrime(i))
                primes.insert(i);
        }

        int min = INT_MAX;
        int n = 2;
        std::vector<int> pairPrimes(n, -1);

        auto it = primes.begin();
        auto prev = it++;

        while (it != primes.end())
        {
            int temp = *it - *prev;
            if (min > temp)
            {
                pairPrimes.clear();
                pairPrimes.push_back(*prev);
                pairPrimes.push_back(*it);

                min = temp;
            }
            it++;
            prev++;
        }
        // for(int i : primes)
        //     std::cout<<i<<" ";

        return pairPrimes;
    }
};
int main()
{
    ClosestPrimeNumbersInRange c1;
    std::vector<int> answer = c1.closestPrimes(11, 35);
    for (int i : answer)
    {
        std::cout << i << " ";
    }

    return 0;
} */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
// #include <cmath>  // For sqrt()

class ClosestPrimeNumbersInRange
{
public:
    std::set<int> primes;

    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int j = 5; j * j <= n; j += 6)
        {
            if (n % j == 0 || n % (j + 2) == 0)
                return false;
        }
        return true;
    }

    std::vector<int> closestPrimes(int left, int right)
    {
        if (left == 1)
            left++;
        if (right == 1 || left == right || right < left)
            return {-1, -1};

        for (int i = left; i <= right; i++)
        {
            if (isPrime(i))
                primes.insert(i);
        }

        if (primes.size() < 2)
            return {-1, -1}; // If there are fewer than two primes, return -1

        int minDiff = INT_MAX;
        std::vector<int> pairPrimes(2, -1);

        auto it = primes.begin();
        auto prev = it++;

        while (it != primes.end())
        {
            int temp = *it - *prev;
            if (minDiff > temp)
            {
                pairPrimes[0] = *prev;
                pairPrimes[1] = *it;
                minDiff = temp;
            }
            it++;
            prev++;
        }

        return pairPrimes;
    }
};

int main()
{
    ClosestPrimeNumbersInRange c1;
    std::vector<int> answer = c1.closestPrimes(11, 35);
    for (int i : answer)
    {
        std::cout << i << " ";
    }

    return 0;
}
