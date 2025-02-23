/* #include <vector>
#include <iostream>
#include <algorithm> // Needed for std::find

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

class ConstructBinaryTreefromPreorderandPostorderTraversal_889
{
public:
    TreeNode *constructFromPrePost(std::vector<int> &preorder, std::vector<int> &postorder)
    {
        if (preorder.empty())
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        if (preorder.size() == 1)
        {
            return root;
        }

        auto pos = std::find(postorder.begin(), postorder.end(), preorder[1]);
        int leftSize = std::distance(postorder.begin(), pos) + 1;

        // Fixed: Using preorder for rightPreOrder instead of postorder
        std::vector<int> leftPreOrder(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
        std::vector<int> leftPostOrder(postorder.begin(), postorder.begin() + leftSize);

        std::vector<int> rightPreOrder(preorder.begin() + 1 + leftSize, preorder.end());
        std::vector<int> rightPostOrder(postorder.begin() + leftSize, postorder.end() - 1);

        root->left = constructFromPrePost(leftPreOrder, leftPostOrder);
        root->right = constructFromPrePost(rightPreOrder, rightPostOrder);

        return root;
    }

    void inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorderTraversal(root->left);
        std::cout << root->val << " "; // Added space for better output formatting
        inorderTraversal(root->right);
    }
};

int main()
{
    ConstructBinaryTreefromPreorderandPostorderTraversal_889 c1;
    std::vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> postOrder = {4, 5, 2, 6, 7, 3, 1};

    TreeNode *root = c1.constructFromPrePost(preOrder, postOrder);
    std::cout << "Inorder Traversal: ";
    c1.inorderTraversal(root);
    std::cout << std::endl; // Added newline for better output formatting

    return 0;
}

// Optimize input/output speed
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
 */

#include <vector>
#include <iostream>
#include <algorithm> // For std::find

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

class ConstructBinaryTreefromPreorderandPostorderTraversal_889
{
public:
    TreeNode *constructFromPrePost(std::vector<int> &preorder, std::vector<int> &postorder)
    {
        return constructHelper(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode *constructHelper(std::vector<int> &preorder, int preStart, int preEnd,
                              std::vector<int> &postorder, int postStart, int postEnd)
    {
        if (preStart > preEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd)
            return root;

        // Find left subtree root position in postorder
        int leftRootVal = preorder[preStart + 1];
        auto pos = std::find(postorder.begin() + postStart, postorder.begin() + postEnd, leftRootVal);
        int leftSize = std::distance(postorder.begin() + postStart, pos) + 1;

        // Recursively build left and right subtrees
        root->left = constructHelper(preorder, preStart + 1, preStart + leftSize, postorder, postStart, postStart + leftSize - 1);
        root->right = constructHelper(preorder, preStart + leftSize + 1, preEnd, postorder, postStart + leftSize, postEnd - 1);

        return root;
    }

public:
    void inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorderTraversal(root->left);
        std::cout << root->val << " ";
        inorderTraversal(root->right);
    }
};

int main()
{
    ConstructBinaryTreefromPreorderandPostorderTraversal_889 c1;
    std::vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> postOrder = {4, 5, 2, 6, 7, 3, 1};

    TreeNode *root = c1.constructFromPrePost(preOrder, postOrder);
    std::cout << "Inorder Traversal: ";
    c1.inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}

// Optimize input/output speed
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
