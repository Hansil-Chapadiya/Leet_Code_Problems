#include <queue>
#include <iostream>
#include <vector>

class ConstructStringWithRepeatLimit_2182
{
public:
    std::string repeatLimitedString(std::string s, int repeatLimit)
    {
        std::priority_queue<char> pq;
        for (char i : s)
        {
            pq.push(i);
        }

        int cnt = 1;
        char last_top = pq.top();
        pq.pop();
        std::string repeatLimitedString;
        repeatLimitedString += last_top;

        while (!pq.empty())
        {
            if (last_top == pq.top())
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }

            if (cnt <= repeatLimit)
            {
                repeatLimitedString += pq.top();
                last_top = pq.top();
                pq.pop();
            }
            else
            {
                char repeat_char = pq.top();
                int repeat = 0;

                // Make sure we do not access pq.top() if pq is empty
                while (!pq.empty() && pq.top() == repeat_char)
                {
                    repeat++;
                    pq.pop();
                }

                if (pq.empty())
                {
                    return repeatLimitedString;
                }
                else
                {
                    repeatLimitedString += pq.top();
                    last_top = pq.top();
                    pq.pop();

                    while (repeat > 0)
                    {
                        pq.push(repeat_char);
                        repeat--; // Decrement repeat to avoid infinite loop
                    }
                }
            }
        }

        return repeatLimitedString;
    }
};

int main()
{
    std::string s = "cczazcc";
    ConstructStringWithRepeatLimit_2182 c1;
    std::cout << c1.repeatLimitedString(s, 3);
    return 0;
}
