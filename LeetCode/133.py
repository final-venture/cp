# Own
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        if not node.neighbors:
            return Node(val=node.val)

        o2n = {}
        q = deque()
        q.append(node)

        while q:
            old = q.popleft()

            if old in o2n:
                new = o2n[old]
            else:
                new = Node(val=old.val)
                o2n.update({old: new})
    
            for nei in old.neighbors:
                if nei in o2n:
                    new.neighbors.append(o2n[nei])
                    continue
                tmp = Node(val=nei.val)
                new.neighbors.append(tmp)
                q.append(nei)
                o2n.update({nei: tmp})

        return o2n[node]

# Little Optimisation
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        o2n = {node: Node(val=node.val)}
        q = deque([node])

        while q:
            old = q.popleft()
            new = o2n[old]

            for nei in old.neighbors:
                if nei not in o2n:
                    q.append(nei)
                    o2n[nei] = Node(val=nei.val)
                new.neighbors.append(o2n[nei])

        return o2n[node]
