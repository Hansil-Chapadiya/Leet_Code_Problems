#include <iostream>
#include <vector>
#include <unordered_map>

/* Produce wrong result */
/* class CheckIfArrayPairsDivisibleByk_1497
{
public:
    bool canArrange(std::vector<int> &arr, int k)
    {
        std::unordered_map<int, int> h_map;
        for (int i = 0; i < (arr.size()/2); i++)
        {
            for (int j = (arr.size()/2); j < arr.size(); j++)
            {
                if ((arr[i] + arr[j]) % k == 0)
                {
                    h_map.insert({arr[i], arr[j]});
                    break;
                }
            }
        }
        if (h_map.size() == (arr.size()/2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}; */

// int main()
// {
//     CheckIfArrayPairsDivisibleByk_1497 C1;
//     std::vector<int> arr = {1,2,3,4,5,10,6,7,8,9};
//     std::cout << C1.canArrange(arr, 5);
//     return 0;
// }

class CheckIfArrayPairsDivisibleByk_1497
{
public:
    bool canArrange(std::vector<int> &arr, int k)
    {
        std::unordered_map<int, int> rem_cnt;

        // Count the frequency of remainders
        for (int num : arr)
        {
            int rem = ((num % k) + k) % k; // Handle negative remainders
            rem_cnt[rem]++;
        }

        // Check for valid pairs
        for (auto &val : rem_cnt)
        {
            int rem = val.first;
            int count = val.second;

            // For remainder 0, the count must be even to form pairs
            if (rem == 0)
            {
                if (count % 2 != 0)
                    return false;
            }
            else
            {
                // For any other remainder `r`, its count must match the count of `k - r`
                if (rem_cnt[rem] != rem_cnt[k - rem])
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckIfArrayPairsDivisibleByk_1497 C1;
    std::vector<int> arr = {75,5,-5,75,-2,-3,88,10,10,87};
    std::cout << (C1.canArrange(arr, 85) ? "True" : "False") << std::endl;
    return 0;
}
static const int hansil = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();