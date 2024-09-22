#include <iostream>

class KthSmallestLexicographical
{
public:
    // Helper function to calculate how many numbers are between `curr` and `curr + 1`
    long long countSteps(long long curr, long long n)
    {
        long long steps = 0;
        long long first = curr;
        long long last = curr;
        while (first <= n)
        {
            steps += std::min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k)
    {
        int curr = 1;
        k--; // We already consider the first number '1'

        while (k > 0)
        {
            long long steps = countSteps(curr, n);
            if (steps <= k)
            {
                // Skip the current subtree and go to the next sibling
                curr++;
                k -= steps;
            }
            else
            {
                // Go deeper in the current subtree
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};

int main()
{
    KthSmallestLexicographical solution;
    int n = 13;
    // int n = 1;
    int k = 2;
    // int k = 1;
    std::cout << "The " << k << "-th smallest number in lexicographical order is: "
              << solution.findKthNumber(n, k) << std::endl;
    return 0;
}
static const int hansil = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
