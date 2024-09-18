#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class LargestNumber_179
{
public:
    string largestNumber(vector<int> &nums)
    {
        // Sort the numbers using a lambda expression
        sort(nums.begin(), nums.end(), [](int a, int b)
             {
        // Convert both integers to strings
        string string1 = to_string(a);
        string string2 = to_string(b);

        // Compare concatenated results
        return string1 + string2 > string2 + string1; });

        if (nums[0] == 0)
        {
            return "0";
        }
        // Concatenate sorted numbers to form the largest number
        string result = "";
        for (int num : nums)
        {
            result += to_string(num);
        }

        return result;
    }
};
int main()
{
    LargestNumber_179 l1;
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << l1.largestNumber(nums);
}
