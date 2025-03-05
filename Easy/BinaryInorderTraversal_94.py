from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BinaryInorderTraversal_94:
    def __init__(self):
        self.result = []  # Use an instance variable instead of a class variable

    def inOrder(self, root: Optional[TreeNode]):
        if root is None:
            return
        self.inOrder(root.left)
        self.result.append(root.val)
        self.inOrder(root.right)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.result = []  # Reset result for each traversal
        self.inOrder(root)
        return self.result

# Example Usage:
# Constructing a sample binary tree
#         1
#          \
#           2
#          /
#         3

node = TreeNode(1)
node.right = TreeNode(2)
node.right.left = TreeNode(3)

obj = BinaryInorderTraversal_94()
print(obj.inorderTraversal(node))  # Output: [1, 3, 2]
