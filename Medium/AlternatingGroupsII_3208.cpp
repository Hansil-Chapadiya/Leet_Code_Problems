/* #include <iostream>
#include <vector>

class AlternatingGroupsII_3208
{
public:
    int numberOfAlternatingGroups(std::vector<int> &colors, int k)
    {
        int n = colors.size();
        int index = 0;
        if (n < k)
        {
            return 0;
        }
        for (int i = 1; i < n; i++)
        {
            if (i == colors.size() - 1 && colors[n - 1] == colors[0])
            {
                index = 0;
                break;
            }
            if (colors[i - 1] == colors[i])
            {

                index = i;
                break;
            }
        }

        int cnt = 0;
        for (int i = index; i < n; ++i)
        {
            bool alternating = true;
            for (int j = 1; j < k; ++j)
            {
                if (colors[(i + j - 1) % n] == colors[(i + j) % n])
                {
                    alternating = false;
                    break;
                }
            }
            if (alternating)
            {
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    AlternatingGroupsII_3208 a1;
    // std::vector<int> colors = {0, 1, 0, 1, 0};
    std::vector<int> colors = {0, 1, 0, 0, 1, 0, 1};
    std::cout << a1.numberOfAlternatingGroups(colors, 6) << std::endl;
    return 0;
} */

#include <iostream>
#include <vector>

class AlternatingGroupsII_3208 {
public:
    int numberOfAlternatingGroups(std::vector<int> &colors, int k) {
        int n = colors.size();
        if (n < k) return 0; // Not enough elements

        int cnt = 0, valid_count = 0;

        // Handle circular array by checking `2n - 1` elements
        for (int i = 1; i < k; ++i) {
            if (colors[i] != colors[i - 1]) valid_count++;
        }

        // First window check
        if (valid_count == k - 1) cnt++;

        // Sliding window from 1 to `n` (to wrap circularly)
        for (int i = 1; i < n; ++i) {
            int remove_idx = i - 1;
            int add_idx = (i + k - 1) % n;

            // Remove outgoing effect
            if (colors[remove_idx] != colors[(remove_idx + 1) % n]) valid_count--;

            // Add new incoming effect
            if (colors[add_idx] != colors[(add_idx - 1 + n) % n]) valid_count++;

            // If we have `k-1` valid transitions, it's a valid group
            if (valid_count == k - 1) cnt++;
        }

        return cnt;
    }
};

int main() {
    AlternatingGroupsII_3208 a1;
    std::vector<int> colors = {0, 1, 0, 0, 1, 0, 1};
    std::cout << a1.numberOfAlternatingGroups(colors, 6) << std::endl;
    return 0;
}
