#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
class CheckIfNanditsDoubleExists_1346
{
private:
public:
    bool checkIfExist(std::vector<int> &arr)
    {
        std::unordered_set<int> seen;
        for (int num : arr)
        {
            // Check if the current number's double or half exists in the set
            if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2)))
            {
                return true;
            }
            // Add the current number to the set
            seen.insert(num);
        }
        return false;
    }
};
int main()
{
    CheckIfNanditsDoubleExists_1346 c1;
    // std::vector<int> arr = {10, 2, 5, 3};
    std::vector<int> arr = {3, 1, 7, 11};
    std::cout << c1.checkIfExist(arr);
    return 0;
}