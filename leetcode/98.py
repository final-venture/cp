# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.val = True
        def dfs(root, lb, ub):
            if self.val == False:
                return
            if not lb < root.val < ub:
                self.val = False
            if root.left:
                dfs(root.left, lb, root.val)
            if root.right:
                dfs(root.right, root.val, ub)
        
        dfs(root, -inf, inf)
        return self.val
