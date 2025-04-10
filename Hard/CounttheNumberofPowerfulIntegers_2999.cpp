#include <iostream>
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
