#include <iostream>
#include <string>
using namespace std;

class SumOfDigitOfString_1945
{
public:
    int getLucky(string s, int k)
    {
        string transform_str = "";

        for (char ch : s)
        {
            int num = ch - 'a' + 1;
            transform_str += to_string(num);
        }

        int sum = 0;
        // Repeat the sum process k times
        for (int i = 0; i < k; i++)
        {
            sum = 0;
            for (char digit : transform_str)
            {
                sum += digit - '0'; // Convert char to int and sum it up
            }
            transform_str = to_string(sum);
        }

        return sum;
    }
};

int main()
{
    SumOfDigitOfString_1945 solver;
    string s = "leetcode";
    int k = 2;
    cout << solver.getLucky(s, k) << endl; // Example output: 6
    return 0;
}
