#include <iostream>
#include <vector>
#include <algorithm>

class MergeTwoSortedArray
{
public:
    std::vector<int> sortedArray(std::vector<int> arr1, std::vector<int> arr2)
    {
        for (int i = 0; i < arr2.size(); i++)
        {
            arr1.push_back(arr2[i]);
        }

        std::sort(arr1.begin(), arr1.end());
        return arr1;
    }
};

int main()
{
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {6, 7, 8, 9, 10};

    MergeTwoSortedArray m1;
    std::vector<int> answer = m1.sortedArray(arr1, arr2);

    for (int i : answer)
    {
        std::cout << i << " ";
    }

    return 0;
}