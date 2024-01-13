# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if not root:
            return res

        q = deque([root])
        while q:
            length = len(q)
            for i in range(len(q)):
                r = q.popleft()
                if i == length - 1:
                    res.append(r.val)
                if r.left:
                    q.append(r.left)
                if r.right:
                    q.append(r.right)

        return res
