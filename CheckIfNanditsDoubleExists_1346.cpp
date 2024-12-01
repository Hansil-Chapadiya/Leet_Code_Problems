#include <iostream>
#include <vector>
#include <unordered_map>
class CheckIfNanditsDoubleExists_1346
{
private:
public:
    bool checkIfExist(std::vector<int> &arr)
    {
        std::unordered_map<int, int> isExists;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 1; j < arr.size(); j++)
            {
                if (i != j)
                {
                    if (arr[i] == (2 * arr[j]))
                    {
                        isExists[arr[i]]++;
                        break;
                    }
                    else if (arr[i] == (arr[j] / 2) && arr[j] % 2 == 0)
                    {
                        isExists[arr[i]]++;
                        break;
                    }
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (isExists.find(arr[i]) != isExists.end())
            {
                flag = 1;
                break;
            }
        }
        return flag ? true : false;
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