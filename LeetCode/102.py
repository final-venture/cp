# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        q = deque([(root, root.val)])

        while q:
            temp = []
            for i in range(len(q)):
                r, v = q.pop()
                temp.append(v)
                if r.left:
                    q.appendleft((r.left, r.left.val))
                if r.right:
                    q.appendleft((r.right, r.right.val))
            res.append(temp)

        return res
        