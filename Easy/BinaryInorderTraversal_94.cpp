#include <iostream>
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
class BinaryInorderTraversal_94
{
private:
    std::vector<int> result;
    void inOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inOrder(root->left);
        result.push_back(root->val);
        inOrder(root->right);
    }

public:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        inOrder(root);
        return result;
    }
};
int main()
{
    TreeNode *root;
    root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    BinaryInorderTraversal_94 b1;
    std::vector<int> answer = b1.inorderTraversal(root);
    for (int i : answer)
    {
        std::cout << i << " ";
    }
    return 0;
}