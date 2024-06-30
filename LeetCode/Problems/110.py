# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.status = True

        if not root:
            return self.status
        
        def detectDepth(tree):
            if self.status == False:
                return 0
            else:
                if tree.left:
                    ld = 1 + detectDepth(tree.left)
                else:
                    ld = 0
                    
                if tree.right:
                    rd = 1 + detectDepth(tree.right)
                else:
                    rd = 0
                
                if abs(ld - rd) > 1:
                    self.status = False
                
                return max(ld, rd)
            
        detectDepth(root)
        return self.status

# Had a stroke on this problem...
