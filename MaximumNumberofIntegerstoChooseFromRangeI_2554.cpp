#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
class MaximumNumberofIntegerstoChooseFromRangeI_2554
{
private:
    bool binarySearch_(std::vector<int> &banned, int num)
    {
        int low = 0;
        int high = banned.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (banned[mid] == num)
            {
                return true;
            }
            else if (banned[mid] < num)
            {
                low = mid + 1;
            }
            else if (banned[mid] > num)
            {
                high = mid - 1;
            }
        }
        return false;
    }

public:
    int maxCount(std::vector<int> &banned, int n, int maxSum)
    {
        std::sort(banned.begin(), banned.end());
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (binarySearch_(banned, i))
            {
                continue;
            }
            maxSum -= i;

            if (maxSum < 0)
            {
                break;
            }
            cnt++;
        }
        return cnt;
    }
};
int main()
{
    std::vector<int> banned = {1, 6, 5};
    int n = 5;
    int maxSum = 6;
    MaximumNumberofIntegerstoChooseFromRangeI_2554 m1;
    std::cout << m1.maxCount(banned, n, maxSum);
    return 0;
}