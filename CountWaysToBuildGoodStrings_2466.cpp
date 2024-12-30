#include <iostream>
#include <cmath>
#include <vector>
class CountWaysToBuildGoodStrings_2466
{
private:
    /* data */
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        long long mod = std::pow(10, 9) + 7;
        std::vector<int> dp(high + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= high; i++)
        {
            if (i >= zero)
            {
                dp[i] = (dp[i] + dp[i - zero]) % mod;
            }
            if (i >= one)
            {
                dp[i] = (dp[i] + dp[i - one]) % mod;
            }
        }

        int result = 0;
        for (int i = low; i <= high; i++)
        {
            result = (result + dp[i]) % mod;
        }
        return result;
    }
};
int main()
{
    CountWaysToBuildGoodStrings_2466 c1;
    std::cout<<c1.countGoodStrings(3, 3, 1, 1);
    return 0;
}
