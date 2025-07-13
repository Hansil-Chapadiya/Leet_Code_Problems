#include <iostream>
#include <queue>

class TreeNode
{
  public:
  int val;
  TreeNode *node;
  TreeNode *right;
  TreeNode *left;
  TreeNode():val(0),left(nullptr),right(nullptr){}
  TreeNode(int x):val(x), left(nullptr),right(nullptr){}
  TreeNode(int x, TreeNode *left, TreeNode *right):val(x),left(left),right(right){}
};
class DFS
{
  public:
  void iterativebfs(TreeNode *root)
  {
    std::queue<TreeNode *> q;
    TreeNode *cur = root;
    q.push(root);

    while(!q.empty())
    {

        cur = q.front();
        q.pop();
        std::cout << cur->val << " ";



        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }

  }
};
int main()
{
    TreeNode *root = new TreeNode(10);

    DFS d;
    root->left = new TreeNode(12);
    root->right = new TreeNode(14);
    root->left->left = new TreeNode(13);
    root->right->right = new TreeNode(15);
    d.iterativebfs(root);
    return 0;
}