#include<iostream>
#include<vector>
#include<algorithm>

class SearchInTwoDArray
{
public:
    bool search(std::vector<std::vector<int>> array, int target)
    {
        int n = array.size();
        int m = array[0].size();

        for (int i = 0; i < n; i++)
        {
            if (std::find(array[i].begin(), array[i].end(), target) != array[i].end())
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    std::vector<std::vector<int>> array = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    SearchInTwoDArray s1;
    std::cout << std::boolalpha << s1.search(array, 8);
    return 0;
}
