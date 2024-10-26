#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Maps to store the unique ID and depth of each node, and the size of each subtree
    std::unordered_map<int, int> nodeToID, depthMap, subtreeSize;
    int idCounter = 0; // Counter to assign unique IDs

    std::vector<int> treeQueries(TreeNode* root, std::vector<int>& queries) {
        // First, perform a DFS to fill in the maps
        dfs(root, 0);

        // Prepare arrays to store maximum heights from the left and right for each node
        std::vector<int> leftMax(idCounter), rightMax(idCounter);

        // Fill leftMax: store the maximum depth from the left up to each node
        for (int i = 0; i < idCounter; i++) {
            leftMax[i] = depthMap[i];
            if (i > 0) leftMax[i] = std::max(leftMax[i - 1], leftMax[i]);
        }

        // Fill rightMax: store the maximum depth from the right up to each node
        for (int i = idCounter - 1; i >= 0; i--) {
            rightMax[i] = depthMap[i];
            if (i + 1 < idCounter) rightMax[i] = std::max(rightMax[i], rightMax[i + 1]);
        }

        // Prepare the result for each query
        std::vector<int> result;
        for (int query : queries) {
            int nodeID = nodeToID[query]; // Get the unique ID for the query node
            int leftIndex = nodeID; // Starting index for left subtree
            int rightIndex = leftIndex + subtreeSize[nodeID] - 1; // Ending index for right subtree

            int newHeight = 0; // Variable to store the new height after removal

            // Check the maximum height from the left if it exists
            if (leftIndex > 0) {
                newHeight = std::max(newHeight, leftMax[leftIndex - 1]);
            }
            // Check the maximum height from the right if it exists
            if (rightIndex + 1 < rightMax.size()) {
                newHeight = std::max(newHeight, rightMax[rightIndex + 1]);
            }

            result.push_back(newHeight); // Store the result for this query
        }

        return result; // Return the results of all queries
    }

    int dfs(TreeNode* root, int height) {
        if (root == nullptr) {
            return 0; // Return 0 for null nodes
        }

        // Assign a unique ID to this node and record its depth
        nodeToID[root->val] = idCounter;
        depthMap[idCounter] = height;
        idCounter++;

        // Recursively calculate the size of the left and right subtrees
        int leftSize = dfs(root->left, height + 1);
        int rightSize = dfs(root->right, height + 1);

        // Store the size of the subtree rooted at this node
        subtreeSize[nodeToID[root->val]] = 1 + leftSize + rightSize;

        return 1 + leftSize + rightSize; // Return the total size
    }
};

int main() {
    // Example tree construction
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(7);

    // Example queries
    std::vector<int> queries = {4, 3, 6};

    // Create a solution instance and get the result
    Solution sol;
    std::vector<int> heightsAfterQueries = sol.treeQueries(root, queries);

    // Output the results
    for (int height : heightsAfterQueries) {
        std::cout << height << " ";
    }

    return 0;
}
