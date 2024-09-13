// #include <iostream>
// #include <vector>
// using namespace std;

// class XorQueriesOfSubArray_1310
// {
// private:
//     /* data */
// public:
//     vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
//     {
//         vector<int> result;
//         // Iterate over each query
//         for (const auto &query : queries)
//         {
//             int xor_ = 0; // Initialize XOR for the current query
//             // Perform XOR for the range [query[0], query[1]]
//             for (int j = query[0]; j <= query[1]; j++)
//             {
//                 xor_ ^= arr[j]; // XOR each element in the range
//             }
//             result.push_back(xor_); // Store the result of the current query
//         }

//         return result; // Return the results for all queries
//     }
// };
// int main()
// {
//     XorQueriesOfSubArray_1310 x1;
//     // vector<int> arr = {1, 3, 4, 8};
//     vector<int> arr = {4, 8, 2, 10};
//     // vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
//     vector<vector<int>> queries = {{2, 3}, {1, 3}, {0, 0}, {0, 3}};
//     vector<int> result = x1.xorQueries(arr, queries);
//     // for (int i = 0; i < result.size(); i++)
//     // {
//     //     cout<<result.at(i)<<endl;
//     // }
// }

#include <iostream>
#include <vector>
using namespace std;

class XorQueriesOfSubArray_1310
{
public:
    // Function to compute XOR queries on subarrays
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        int n = arr.size();

        // Step 1: Create the prefix XOR array
        // prefix[i] stores XOR of elements from arr[0] to arr[i]
        vector<int> prefix(n);
        prefix[0] = arr[0];  // The first element is the same
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i];  // XOR of previous prefix with the current element
        }

        // Step 2: Answer the queries using the prefix XOR array
        vector<int> result;
        for (int i = 0; i < queries.size(); i++) {
            int L = queries[i][0];  // Starting index of the subarray
            int R = queries[i][1];  // Ending index of the subarray

            // Step 3: Compute the XOR for the subarray arr[L] to arr[R]
            if (L == 0) {
                // If L is 0, we directly use prefix[R]
                result.push_back(prefix[R]);
            } else {
                // Otherwise, use prefix[R] ^ prefix[L - 1]
                result.push_back(prefix[R] ^ prefix[L - 1]);
            }
        }

        // Return the result for all queries
        return result;
    }
};

int main()
{
    // Test case: input array and queries
    vector<int> arr = {4, 8, 2, 10};  // Example array
    vector<vector<int>> queries = {{2, 3}, {1, 3}, {0, 0}, {0, 3}};  // Queries in the format {L, R}

    // Create an object of the class
    XorQueriesOfSubArray_1310 x1;

    // Call the xorQueries function and store the result
    vector<int> result = x1.xorQueries(arr, queries);

    // Output the results of each query
    for (int i = 0; i < result.size(); i++) {
        cout << "XOR of subarray for query " << i + 1 << " is: " << result[i] << endl;
    }

    return 0;
}

/*

Why Use L - 1?
Now, to get the XOR of any subarray from L to R using the prefix XOR array, here’s the trick:

Example:
Let's say we want to find the XOR of the subarray from index L = 1 to R = 3 in arr = [4, 8, 2, 10]. This means we want to find the XOR of arr[1] ^ arr[2] ^ arr[3] (which is 8 ^ 2 ^ 10).

Step-by-Step:

XOR of everything up to R: From the prefix XOR array, we know:

prefix
[
3
]
=
4
prefix[3]=4
This is the XOR of everything from index 0 to 3 (i.e., 4 ^ 8 ^ 2 ^ 10).

XOR of everything before L: Now, we want to "remove" the part of the array before L. We do this by using:

prefix
[
0
]
=
4
prefix[0]=4
This gives the XOR of everything before index 1 (which is just arr[0] = 4).
*/