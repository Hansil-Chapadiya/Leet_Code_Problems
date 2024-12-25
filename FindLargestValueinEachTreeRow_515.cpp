#include <iostream>
#include <vector>
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindLargestValueinEachTreeRow_515
{
private:
    /* data */
public:
    std::vector<int> largestValues(TreeNode *root)
    {
    }
};

int main()
{
    FindLargestValueinEachTreeRow_515 f1;
    TreeNode *root = new TreeNode(2);
    f1.largestValues(root);
    return 0;
}