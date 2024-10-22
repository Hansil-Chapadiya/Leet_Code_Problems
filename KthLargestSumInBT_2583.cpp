#include <iostream>
#include <vector>
#include <algorithm>

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

class KthLargestSumInBT_2583
{
private:
    int height(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lheight = height(root->left);
        int rheight = height(root->right);
        return std::max(lheight, rheight) + 1;
    }

    long long sumCurrentLevel(TreeNode *root, int level)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (level == 1)
        {
            return root->val;
        }
        else if (level > 1)
        {
            // Recursively sum nodes at the current level
            long long leftSum = sumCurrentLevel(root->left, level - 1);
            long long rightSum = sumCurrentLevel(root->right, level - 1);
            return leftSum + rightSum;
        }
        return 0;
    }

public:
    std::vector<long long> track_sum;

    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        if (root == nullptr)
            return -1; // If tree is empty, return -1 or handle error

        int h = height(root);
        for (int i = 1; i <= h; i++)
        {
            track_sum.push_back(sumCurrentLevel(root, i));
        }
        if (k > track_sum.size() || k < 1)
            return -1; // If k is out of bounds, return error value

        // Sort in descending order
        std::sort(track_sum.begin(), track_sum.end(), std::greater<long long>());

        return track_sum[k - 1]; // Return k-th largest sum
    }
};

int main()
{
    KthLargestSumInBT_2583 K1;

    // Creating a sample tree:
    //            20
    //           /  \
    //          8    9
    //         / \  / \
    //        2   1 3  7
    //       / \
    //      4   6
    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(8);
    // root->left->right = new TreeNode(1);
    // root->left->left = new TreeNode(2);
    // root->left->left->left = new TreeNode(4);
    // root->left->left->right = new TreeNode(6);
    // root->right = new TreeNode(9);
    // root->right->right = new TreeNode(7);
    // root->right->left = new TreeNode(3);
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    // Find the 2nd largest level sum
    std::cout << "2nd Largest Level Sum: " << K1.kthLargestLevelSum(root, 1) << std::endl;

    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();