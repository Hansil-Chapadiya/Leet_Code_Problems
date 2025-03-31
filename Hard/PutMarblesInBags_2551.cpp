#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

class PutMarblesInBags_2551 {
public:
    long long putMarbles(std::vector<int>& weights, int k) {
        if (k == 1) return 0; // If there's only one partition, there's no difference

        long long minWeight = 0;
        long long maxWeight = 0;

        std::vector<long long> pairWeightSum;

        // 🔹 Corrected: Compute adjacent pair sums properly
        for (size_t i = 0; i < weights.size() - 1; i++) {
            pairWeightSum.push_back(weights[i] + weights[i + 1]);
        }

        std::sort(pairWeightSum.begin(), pairWeightSum.end());

        // 🔹 Pick (k-1) smallest and largest sums
        for (int i = 0; i < k - 1; i++) {
            minWeight += pairWeightSum[i];
            maxWeight += pairWeightSum[pairWeightSum.size() - 1 - i];
        }

        return maxWeight - minWeight;
    }
};

int main() {
    PutMarblesInBags_2551 p1;
    std::vector<int> weights = {1, 3, 5, 1};
    int k = 2;
    std::cout << p1.putMarbles(weights, k) << std::endl; // Expected output: 4

    return 0;
}
