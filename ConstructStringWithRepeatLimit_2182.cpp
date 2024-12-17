#include <queue>
#include <iostream>
#include <vector>

class ConstructStringWithRepeatLimit_2182
{
private:
    /* data */
public:
    std::string repeatLimitedString(std::string s, int repeatLimit)
    {
        int cnt = 1;
        std::priority_queue<char> pq;
        for (auto i : s)
        {
            pq.push(i);
        }

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
            {
                cnt++;
            }
        }
    }
};
int main()
{
    std::string s = "cczazcc";
    ConstructStringWithRepeatLimit_2182 c1;
    c1.repeatLimitedString(s, 3);
    return 0;
}