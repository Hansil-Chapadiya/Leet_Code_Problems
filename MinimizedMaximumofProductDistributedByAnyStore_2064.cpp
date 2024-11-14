#include <iostream>
#include <vector>
#include <algorithm>

class MinimizedMaximumofProductDistributedByAnyStore_2064
{
private:
    // Helper function to check if the products can be distributed such that no store has more than 'maxProducts' items.
    bool canDistribute(int maxProducts, std::vector<int> &productQuantities, int numStores)
    {
        int currentStore = 0;                         // Track the current store being filled
        int remainingProducts = productQuantities[0]; // Remaining products to distribute from the current batch

        for (int i = 0; i < numStores; i++)
        {
            // If the remaining products for the current store fit within maxProducts limit
            if (remainingProducts <= maxProducts)
            {
                currentStore++;

                // If all products have been distributed
                if (currentStore == productQuantities.size())
                {
                    return true;
                }
                else
                {
                    remainingProducts = productQuantities[currentStore]; // Move to the next product batch
                }
            }
            else
            {
                remainingProducts -= maxProducts; // Reduce remaining products by the max limit for this store
            }
        }
        return false;
    }

public:
    // Main function to find the minimized maximum product load per store
    int minimizedMaximum(int numStores, std::vector<int> &productQuantities)
    {
        int minLoad = 0;
        int maxLoad = *std::max_element(productQuantities.begin(), productQuantities.end());

        // Binary search to determine the minimized maximum load
        while (minLoad < maxLoad)
        {
            int midLoad = (minLoad + maxLoad) / 2;
            if (canDistribute(midLoad, productQuantities, numStores))
            {
                maxLoad = midLoad;
            }
            else
            {
                minLoad = midLoad + 1;
            }
        }

        // Return the minimized maximum load
        return minLoad;
    }
};

int main()
{
    std::vector<int> productQuantities = {11, 6};
    int numStores = 6;

    MinimizedMaximumofProductDistributedByAnyStore_2064 minimizer;
    std::cout << minimizer.minimizedMaximum(numStores, productQuantities);

    return 0;
}
