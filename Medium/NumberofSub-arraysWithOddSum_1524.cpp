#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd_count = 0, even_count = 1; // Start with even_count = 1
        long long prefix_sum = 0, result = 0;

        for (int num : arr) {
            prefix_sum += num;

            if (prefix_sum % 2 == 0) {
                result += odd_count;  // Even prefix sum -> add odd count
                even_count++;
            } else {
                result += even_count;  // Odd prefix sum -> add even count
                odd_count++;
            }

            result %= MOD; // Ensure result doesn't exceed MOD
        }

        return result;
    }
};

int main() {
    vector<int> arr = {1, 3, 5};
    Solution sol;
    cout << sol.numOfSubarrays(arr) << endl; // Output: 4
    return 0;
}
