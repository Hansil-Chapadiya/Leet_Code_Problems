#include <iostream>
#include <vector>
#include <unordered_map>

class TupleWithSameProduct_1726 {
private:
    std::unordered_map<int, int> u_map;

public:
    int tupleSameProduct(std::vector<int> &nums) {
        int totalTuples = 0;

        // Iterate through all unique pairs (i, j) where i < j
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) { // Start from i+1 to avoid duplicates
                int product = nums[i] * nums[j];
                u_map[product]++; // Store frequency of the product
            }
        }

        // Calculate number of valid tuples
        for (const auto &pair : u_map) {
            int count = pair.second;
            if (count > 1) {
                totalTuples += 8 * (count * (count - 1)) / 2;
            }
        }

        return totalTuples;
    }
};

int main() {
    TupleWithSameProduct_1726 t1;

    std::vector<int> nums = {10, 5, 15, 8, 6, 12, 20, 4};

    int result = t1.tupleSameProduct(nums);
    std::cout << "Total Tuples: " << result << std::endl;

    return 0;
}
