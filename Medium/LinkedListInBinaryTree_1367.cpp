// #include <iostream>
// using namespace std;

// class ListNode
// {
// public:
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class TreeNode
// {
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class LinkedListInBinaryTree_1367
// {
// public:
//     // Main function to check if the linked list is a subpath in the binary tree
//     bool isSubPath(ListNode *head, TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return false;
//         }
//         // Check if the linked list matches from the current root
//         if (doesPathMatch(head, root))
//         {
//             return true;
//         }
//         // Recursively check left and right subtrees
//         return isSubPath(head, root->left) || isSubPath(head, root->right);
//     }

// private:
//     // Helper function to check if the linked list matches a downward path starting from the tree node
//     bool doesPathMatch(ListNode *head, TreeNode *node)
//     {
//         if (head == nullptr)
//         {
//             return true; // We have reached the end of the linked list
//         }
//         if (node == nullptr || head->val != node->val)
//         {
//             return false; // Either the tree node is null, or the values don't match
//         }
//         // Check both left and right subtrees for a continuing match
//         return doesPathMatch(head->next, node->left) || doesPathMatch(head->next, node->right);
//     }
// };

// // Pre-order traversal function for the binary tree
// void preOrderTraversal(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     cout << root->val << " ";
//     preOrderTraversal(root->left);
//     preOrderTraversal(root->right);
// }

// int main()
// {
//     // Creating a linked list: 4 -> 2 -> 8
//     ListNode *head = new ListNode(4);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(8);

//     // Creating a binary tree
//     /*
//              1
//            /   \
//           4     4
//            \   /
//             2 2
//            /  \
//           1    6
//               / \
//              8   8
//     */
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(4);
//     root->left->right = new TreeNode(2);
//     root->left->right->left = new TreeNode(1);

//     root->right = new TreeNode(4);
//     root->right->left = new TreeNode(2);
//     root->right->left->left = new TreeNode(6);
//     root->right->left->right = new TreeNode(8);

//     LinkedListInBinaryTree_1367 solution;
//     bool result = solution.isSubPath(head, root);
//     cout << (result ? "True" : "False") << endl; // Expected output: True (the path 4 -> 2 -> 8 exists)

//     return 0;
// }

#include <iostream>
#include <stack>
#include <utility>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

class LinkedListInBinaryTree_1367
{
public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (root == nullptr)
            return false;

        // Stack to store TreeNode and current ListNode pointers
        stack<pair<TreeNode *, ListNode *>> s;
        s.push(make_pair(root, head));

        while (!s.empty())
        {
            TreeNode *currentTreeNode = s.top().first;
            ListNode *currentListNode = s.top().second;
            s.pop();

            // Check if we've completed the entire linked list
            if (currentListNode == nullptr)
                return true;

            // If the tree node is null, skip further exploration
            if (currentTreeNode == nullptr)
                continue;

            // If current node matches the linked list node, proceed
            if (currentTreeNode->val == currentListNode->val)
            {
                if (currentListNode->next == nullptr)
                    return true;

                // Only push the matching next nodes
                if (currentTreeNode->left != nullptr)
                    s.push(make_pair(currentTreeNode->left, currentListNode->next));

                if (currentTreeNode->right != nullptr)
                    s.push(make_pair(currentTreeNode->right, currentListNode->next));
            }

            // Explore new paths starting at the current node, but reset the list pointer
            if (currentTreeNode->left != nullptr)
                s.push(make_pair(currentTreeNode->left, head));

            if (currentTreeNode->right != nullptr)
                s.push(make_pair(currentTreeNode->right, head));
        }

        return false;
    }
};

int main()
{
    // Example linked list: 1 -> 4 -> 2 -> 6 -> 8
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(8);

    // Example binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);
    root->right->left->right->left = new TreeNode(1);
    root->right->left->right->right = new TreeNode(3);

    LinkedListInBinaryTree_1367 solver;
    bool result = solver.isSubPath(head, root);

    if (result)
    {
        cout << "The linked list is a subpath of the binary tree." << endl;
    }
    else
    {
        cout << "The linked list is NOT a subpath of the binary tree." << endl;
    }

    return 0;
}
static const int hansil = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();