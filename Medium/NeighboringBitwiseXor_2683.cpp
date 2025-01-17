/* #include <iostream>
#include <vector>

class NeighboringBitwiseXor_2683
{
public:
    bool doesValidArrayExist(std::vector<int> &derived)
    {
        // Check if derived is empty
        if (derived.empty())
            return false;

        // Create a copy of the derived vector to validate XOR
        std::vector<int> temp = derived;

        // Traverse and calculate XOR sequentially
        for (size_t i = 1; i < temp.size(); i++)
        {
            temp[i - 1] = temp[i] ^ temp[i - 1];
        }

        // Validate the last element
        temp[temp.size() - 1] = temp[temp.size() - 2] ^ temp[0];

        // Check if all elements are binary (0 or 1)
        for (auto num : temp)
        {
            std::cout << num << " ";
            if (num != 0 && num != 1)
                return false;
        }

        return true;
    }
};

int main()
{
    std::vector<int> derived = {1, 0}; // Test case
    NeighboringBitwiseXor_2683 n1;
    std::cout << n1.doesValidArrayExist(derived) << std::endl; // Output result
    return 0;
}
 */

#include <iostream>
#include <vector>

class NeighboringBitwiseXor_2683
{
public:
    bool doesValidArrayExist(std::vector<int> &derived)
    {
        int n = derived.size();

        // Helper function to verify a reconstruction
        auto canReconstruct = [&](int start) -> bool
        {
            std::vector<int> original(n);
            original[0] = start;

            // Reconstruct the original array
            for (int i = 1; i < n; i++)
            {
                original[i] = original[i - 1] ^ derived[i - 1];
                if (original[i] != 0 && original[i] != 1) // Must stay binary
                    return false;
            }

            // Check the wraparound condition
            return (original[n - 1] ^ original[0]) == derived[n - 1];
        };

        // Try both possible starting values for original[0]
        return canReconstruct(0) || canReconstruct(1);
    }
};

int main()
{
    std::vector<int> derived = {1, 0}; // Example test case
    NeighboringBitwiseXor_2683 n1;
    std::cout << std::boolalpha << n1.doesValidArrayExist(derived) << std::endl; // Output result
    return 0;
}

/*
bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans ^= derived[i];
        }
        if(ans == 0)return true;
        return false;
    }
*/