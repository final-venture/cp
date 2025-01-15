# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# recursive dfs
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        def detectDepth(root, depth):
            if root:
                depth = max(detectDepth(root.left, depth+1), detectDepth(root.right, depth+1))
            return depth

        return detectDepth(root, 0)

# iterative dfs
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        res = 0
        stack = [(root, 0)]
        while stack:
            for i in range(len(stack)):
                r, d = stack.pop()
                if r:
                    stack.append((r.left, d+1))
                    stack.append((r.right, d+1))
                res = max(res, d)
        return res

# iterative bfs
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        layer = 0
        q = deque([root])

        while q:
            for i in range(len(q)):
                r = q.popleft()
                if r.left:
                    q.append(r.left)
                if r.right:
                    q.append(r.right)
            layer += 1

        return layer
