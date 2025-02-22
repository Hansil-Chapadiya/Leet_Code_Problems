from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class RecoverTreeFromPreorderTraversal_1028:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        __stack = []
        i = 0
        while i < len(traversal):
            depth = 0
            while i < len(traversal) and traversal[i] == "-":
                depth += 1
                i += 1

            num = 0
            while i < len(traversal) and traversal[i].isdigit():
                num = (num * 10) + int(traversal[i])
                i += 1  # Fix: Increment i while reading number

            node = TreeNode(num)

            if depth == 0:
                root = node
            else:
                while len(__stack) > depth:
                    __stack.pop()
                parent = __stack[-1]

                if not parent.left:
                    parent.left = node
                else:
                    parent.right = node

            __stack.append(node)

        return root

    def levelOrder(self, root, level, result):
        if not root:
            return

        if len(result) <= level:
            result.append([])

        result[level].append(root.val)

        self.levelOrder(root.left, level + 1, result)
        self.levelOrder(root.right, level + 1, result)

    def bfs(self, root):
        res = []
        self.levelOrder(root, 0, res)
        return res


# # Helper function to print the tree (inorder traversal)
# def print_tree(root, indent=0):
#     if root:
#         print_tree(root.right, indent + 4)
#         print(" " * indent + str(root.val))
#         print_tree(root.left, indent + 4)


# Example Usage
s = "1-2--3--4-5--6--7"
class_ = RecoverTreeFromPreorderTraversal_1028()
tree_root = class_.recoverFromPreorder(traversal=s)
result = class_.bfs(tree_root)
print(result)
# print_tree(tree_root)
