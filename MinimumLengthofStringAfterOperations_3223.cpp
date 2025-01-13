#include <iostream>
#include <string>
#include <unordered_map>
#include <numeric>
class MinimumLengthofStringAfterOperations_3223
{
private:
    /* data */
public:
    int minimumLength(std::string s)
    {
        std::unordered_map<char, int> u_map;
        for (auto c : s)
        {
            u_map[c]++;
        }
        for (auto c : u_map)
        {
            std::cout << c.first << " " << c.second << " ";
            if (c.second % 2 == 0)
            {
                while (c.second > 2)
                {
                    c.second--;
                }
            }
            else
            {
                while (c.second > 1)
                {
                    c.second--;
                }
            }
            u_map[c.first] = c.second;
        }
        return std::accumulate(
            u_map.begin(), u_map.end(), 0,
            [](int acc, const auto &pair)
            {
                return acc + pair.second; // Sum up the values
            });
    }
};
int main()
{
    MinimumLengthofStringAfterOperations_3223 m1;
    std::cout << m1.minimumLength("abaacbcbb");
    return 0;
}