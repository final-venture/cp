# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        diameter = 0

        def dfs(node):
            if node.left:
                le = dfs(node.left)
            else:
                le = 0
            if node.right:
                re = dfs(node.right)
            else:
                re = 0
            nonlocal diameter
            diameter = max(diameter, le + re)
            edges = 1 + max(le, re)
            return edges
        
        dfs(root)
        return diameter
