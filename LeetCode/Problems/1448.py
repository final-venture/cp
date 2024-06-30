# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.qty = 0
        def dfs(root, mxm):
            if mxm <= root.val:
                self.qty += 1
            if root.left:
                dfs(root.left, max(mxm, root.val))
            if root.right:
                dfs(root.right, max(mxm, root.val))

        dfs(root, -inf)
        return self.qty
