#include <iostream>

class TreeNode
{
public:
    int val;
    TreeNode *node;
    TreeNode *right;
    TreeNode *left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class DFS
{
public:
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        std::cout << root->val << " ";
        dfs(root->right);
    }
};
int main()
{
    TreeNode *root = new TreeNode(10);

    DFS d;
    root->left = new TreeNode(12);
    root->right = new TreeNode(14);
    d.dfs(root);
    return 0;
}

/*


void iterativedfs(TreeNode *root)
  {
    std::stack<TreeNode *> stk;
    TreeNode *cur = root;

    while(cur!=nullptr || !stk.empty())
    {
        while(cur != nullptr)
        {
            stk.push(cur);
            cur = cur->left;
        }

        cur = stk.top();
        stk.pop();

        std::cout << cur->val << " ";

        cur = cur->right;
    }

  }

*/