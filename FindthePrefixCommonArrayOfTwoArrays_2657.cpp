#include <iostream>
#include <vector>
#include <unordered_set>

class FindthePrefixCommonArrayOfTwoArrays_2657
{
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int> &A, std::vector<int> &B)
    {
        std::vector<int> prefixCommon(A.size(), 0);
        std::unordered_set<int> seenA, seenB;

        int commonCount = 0;

        for (int i = 0; i < A.size(); i++)
        {
            // Add current elements to their respective sets
            if (seenB.count(A[i]))
            {
                commonCount++;
            }
            seenA.insert(A[i]);

            if (seenA.count(B[i]))
            {
                commonCount++;
            }
            seenB.insert(B[i]);

            // Update prefix common array
            prefixCommon[i] = commonCount;
        }

        return prefixCommon;
    }
};

int main()
{
    std::vector<int> A = {1, 3, 2, 4};
    std::vector<int> B = {3, 1, 2, 4};
    FindthePrefixCommonArrayOfTwoArrays_2657 f1;
    std::vector<int> result = f1.findThePrefixCommonArray(A, B);

    // Output the result
    std::cout << "Prefix Common Array: ";
    for (int x : result)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
