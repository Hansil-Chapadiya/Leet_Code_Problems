#include <iostream>

class KthSmallestLexicographical
{
public:
    int findKthNumber(int n, int k) {

    }
};

int main()
{
    KthSmallestLexicographical solution;
    int n = 13;
    int k = 2;
    std::cout << "The " << k << "-th smallest number in lexicographical order is: "
              << solution.findKthNumber(n, k) << std::endl;
    return 0;
}
