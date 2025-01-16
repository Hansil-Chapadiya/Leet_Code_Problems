#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CousinInBinaryTreeII_2641
{
private:
    // Helper function to recursively process the tree level by level
    void processLevel(std::vector<TreeNode *> currentLevelNodes)
    {
        if (currentLevelNodes.size() == 0)
            return; // Handle case where there are no nodes at the current level

        int totalSum = 0; // To calculate the sum of all children in the current level

        // Calculate the total sum of all left and right children of the nodes in the current level
        for (auto node : currentLevelNodes)
        {
            if (!node)
            {
                continue;
            }

            // Sum the values of left and right children of each node
            if (node->left)
                totalSum += node->left->val;
            if (node->right)
                totalSum += node->right->val;
        }

        std::vector<TreeNode *> nextLevelNodes; // Store the nodes for the next level

        // Update the values of children based on the cousin sum logic
        for (auto node : currentLevelNodes)
        {
            int siblingSum = 0;

            // Calculate the sum of the current node's children (i.e., its siblings' values)
            if (node->left)
                siblingSum += node->left->val;
            if (node->right)
                siblingSum += node->right->val;

            // Update left child's value with the sum of cousins (totalSum - siblingSum)
            if (node->left)
            {
                node->left->val = totalSum - siblingSum;
                nextLevelNodes.push_back(node->left); // Add to the next level nodes
            }

            // Update right child's value with the sum of cousins (totalSum - siblingSum)
            if (node->right)
            {
                node->right->val = totalSum - siblingSum;
                nextLevelNodes.push_back(node->right); // Add to the next level nodes
            }
        }

        // Recursively process the next level
        processLevel(nextLevelNodes);
    }

public:
    // Function to replace the node values with the sum of cousins
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        root->val = 0;                               // The root node doesn't have any cousins, so its value becomes 0
        processLevel(std::vector<TreeNode *>{root}); // Start processing from the root level
        return root;                                 // Return the modified tree
    }
    void preOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        std::cout << root->val << std::endl;
        preOrder(root->left);
        preOrder(root->right);
    }
};

int main()
{
    CousinInBinaryTreeII_2641 c1;

    // Example tree: [5,4,9,1,10,null,7]
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(10);
    root->right = new TreeNode(9);
    root->right->right = new TreeNode(7);

    // Replace values in the tree with cousin sums

    c1.preOrder(c1.replaceValueInTree(root));
    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();