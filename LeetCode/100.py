# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        self.res = True
        if not p and not q:
            return True
        elif not p or not q:
            return False

        def isSimilar(p, q):
            if self.res is False:
                return

            if p.val != q.val:
                self.res = False

            if p.left and q.left:
                isSimilar(p.left, q.left)
            elif not p.left and not q.left:
                pass
            else:
                self.res = False
            
            if p.right and q.right:
                isSimilar(p.right, q.right)
            elif not p.right and not q.right:
                pass
            else:
                self.res = False
        
        isSimilar(p, q)
        return self.res
