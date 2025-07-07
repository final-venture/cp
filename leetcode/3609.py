class Solution:
    def minMoves(self, sx: int, sy: int, tx: int, ty: int) -> int:
        dq = deque([(tx, ty, 0)])
        seen = set()
        while dq:
            cx, cy, steps = dq.popleft()
            if (cx == sx and cy == sy):
                return steps
            if ((cx, cy) in seen):
                continue
            seen.add((cx, cy))
            if cx % 2 == 0 and cx // 2 >= cy:
                dq.append((cx // 2, cy, steps + 1))
            if cy % 2 == 0 and cy // 2 >= cx:
                dq.append((cx, cy // 2, steps + 1))
            if cx >= cy and cx - cy <= cy:
                dq.append((cx - cy, cy, steps + 1))
            if cy >= cx and cy - cx <= cx:
                dq.append((cx, cy - cx, steps + 1))

        return -1
