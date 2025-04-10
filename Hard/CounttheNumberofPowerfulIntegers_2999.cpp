/* #include <iostream>
#include <string>

class CounttheNumberofPowerfulIntegers_2999
{
public:
    bool check(const std::string& iStr, int limit)
    {
        for (char c : iStr)
        {
            if ((c - '0') > limit)
                return false;
        }
        return true;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, const std::string& s) {
        long long count = 0;
        for (long long i = start; i <= finish; i++)
        {
            std::string iStr = std::to_string(i);
            // Manual ends_with for compatibility if not using C++20
            if (iStr.size() >= s.size() && iStr.substr(iStr.size() - s.size()) == s && check(iStr, limit))
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    CounttheNumberofPowerfulIntegers_2999 c1;
    std::cout << c1.numberOfPowerfulInt(1, 6000, 4, "124") << std::endl;
    return 0;
}
 */


 #include <iostream>
 #include <vector>
 #include <string>
 #include <functional>
 #include <algorithm>

 class CounttheNumberofPowerfulIntegers_2999 {
 public:
     long long numberOfPowerfulInt(long long start, long long finish, int limit, std::string s) {
         std::string low = std::to_string(start);
         std::string high = std::to_string(finish);
         int n = high.size();

         // Pad the low string with leading zeros to match length
         low = std::string(n - low.size(), '0') + low;
         int pre_len = n - s.size();

         std::vector<std::vector<long long>> memo(n, std::vector<long long>(2, -1));

         std::function<long long(int, bool, bool)> dfs = [&](int i, bool limit_low, bool limit_high) -> long long {
             if (i == low.size()) {
                 return 1;
             }

             if (!limit_low && !limit_high && memo[i][0] != -1) {
                 return memo[i][0];
             }

             int lo = limit_low ? low[i] - '0' : 0;
             int hi = limit_high ? high[i] - '0' : 9;

             long long res = 0;

             if (i < pre_len) {
                 for (int digit = lo; digit <= std::min(hi, limit); digit++) {
                     res += dfs(i + 1, limit_low && digit == lo, limit_high && digit == hi);
                 }
             } else {
                 int x = s[i - pre_len] - '0';
                 if (lo <= x && x <= std::min(hi, limit)) {
                     res = dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
                 }
             }

             if (!limit_low && !limit_high) {
                 memo[i][0] = res;
             }

             return res;
         };

         return dfs(0, true, true);
     }
 };

 int main() {
     CounttheNumberofPowerfulIntegers_2999 c1;
     std::cout << c1.numberOfPowerfulInt(23, 1000, 5, "23") << std::endl;
     return 0;
 }
