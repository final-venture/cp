class Folder:
    def __init__(self):
        self.children = {}
        self.serial = ""

class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = Folder()

        def build(path):
            curr = root
            for d in path:
                if d not in curr.children:
                    curr.children[d] = Folder()
                curr = curr.children[d]

        for path in paths:
            build(path)

        freq = Counter()

        def hash_struct(node):
            if not node.children:
                return

            v = []
            for char, nei in node.children.items():
                hash_struct(nei)
                v.append(f"{char}({nei.serial})")
            
            v.sort()
            node.serial = "".join(v)
            freq[node.serial] += 1

        hash_struct(root)

        ret = []
        path = []

        def dfs(node):
            if freq[node.serial] > 1:
                return
            if path:
                ret.append(path[:])
            for char, nei in node.children.items():
                path.append(char)
                dfs(nei)
                path.pop()

        dfs(root)
        return ret
