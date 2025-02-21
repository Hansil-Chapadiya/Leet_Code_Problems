#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
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
class FindElementsinContaminatedBinaryTree_1261
{
private:
    std::unordered_set<int> findVector;
    std::stack<TreeNode *> stk;

public:
    FindElementsinContaminatedBinaryTree_1261(TreeNode *root)
    {
        root->val = 0;
        stk.push(root);

        TreeNode *p;
        while (!stk.empty())
        {
            p = stk.top();
            stk.pop();
            if (p->left != nullptr)
            {
                p->left->val = 2 * p->val + 1;
                findVector.insert(p->left->val);
                stk.push(p->left);
            }
            if (p->right != nullptr)
            {
                p->right->val = 2 * p->val + 2;
                findVector.insert(p->right->val);
                stk.push(p->right);
            }
        }
    }

    bool find(int target)
    {
        return findVector.find(target) != findVector.end();
    }
};
int main()
{
    TreeNode *root = new TreeNode(-1);
    root->right = new TreeNode(-1);
    FindElementsinContaminatedBinaryTree_1261 *f1 = new FindElementsinContaminatedBinaryTree_1261(root);
    std::cout << f1->find(2);
    return 0;
}
