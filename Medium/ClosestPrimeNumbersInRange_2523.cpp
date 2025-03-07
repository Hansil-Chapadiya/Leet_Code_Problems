#include <iostream>
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
}