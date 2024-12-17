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
/*
#include <iostream>
#include <vector>
#include <string>

class ConstructStringWithRepeatLimit_2182
{
public:
    std::string repeatLimitedString(std::string s, int repeatLimit)
    {
        // Step 1: Count frequencies of each character
        std::vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        std::string result;

        // Step 2: Construct the string
        while (true) {
            // 1. Find the largest character that can be used
            int largest = -1;
            for (int i = 25; i >= 0; --i) { // Look for the largest available character
                if (freq[i] > 0) {
                    largest = i;
                    break;
                }
            }

            if (largest == -1) break; // No more characters available

            // 2. Add the largest character up to repeatLimit times
            int use_count = std::min(freq[largest], repeatLimit);
            for (int i = 0; i < use_count; ++i) {
                result += ('a' + largest);
            }

            freq[largest] -= use_count; // Reduce the frequency of the used character

            // 3. If there are still occurrences of this character left, we need a "breaker" character
            if (freq[largest] > 0) {
                // Find the next largest character to "break" the sequence
                int next_largest = -1;
                for (int i = largest - 1; i >= 0; --i) { // Look for the next smaller character
                    if (freq[i] > 0) {
                        next_largest = i;
                        break;
                    }
                }

                // If no smaller character is available, we are done
                if (next_largest == -1) break;

                // Add the breaker character once
                result += ('a' + next_largest);
                freq[next_largest]--;
            }
        }

        return result;
    }
};

int main()
{
    std::string s = "cczazcc";
    ConstructStringWithRepeatLimit_2182 c1;
    std::cout << c1.repeatLimitedString(s, 3) << std::endl;
    return 0;
}


 */