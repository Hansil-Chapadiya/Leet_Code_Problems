#include <iostream>
#include <vector>
#include <string>

class MaximumScoreAfterSplitingString_1422
{
public:
    int maxScore(const std::string &s)
    {
        int n = s.length();
        std::vector<int> prefixsum_of_ones(n, 0);
        std::vector<int> prefixsum_of_zero(n, 0);

        // Fill prefixsum_of_ones from right to left
        prefixsum_of_ones[n - 1] = (s[n - 1] == '1') ? 1 : 0;
        for (int i = n - 2; i >= 0; i--)
        {
            prefixsum_of_ones[i] = prefixsum_of_ones[i + 1] + (s[i] == '1' ? 1 : 0);
        }

        // Fill prefixsum_of_zero from left to right
        prefixsum_of_zero[0] = (s[0] == '0') ? 1 : 0;
        for (int i = 1; i < n; i++)
        {
            prefixsum_of_zero[i] = prefixsum_of_zero[i - 1] + (s[i] == '0' ? 1 : 0);
        }

        // Calculate the maximum score
        int max_score = 0;
        for (int i = 1; i < n; i++) // Split at each valid position
        {
            int left = prefixsum_of_zero[i - 1];
            int right = prefixsum_of_ones[i];
            max_score = std::max(max_score, left + right);
        }

        return max_score;
    }
};

int main()
{
    MaximumScoreAfterSplitingString_1422 m1;
    std::string s = "011101";
    std::cout << "Maximum Score: " << m1.maxScore(s) << std::endl;
    return 0;
}

/*
class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');

        int ans = 0;
        int zeros = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }

            ans = max(ans, zeros + ones);
        }

        return ans;
    }
};
 */