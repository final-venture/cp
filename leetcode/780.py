class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while sx < tx and sy < ty:
            if (tx > ty):
                tx %= ty
            else:
                ty %= tx

        return (sy == ty and sx <= tx and (sx - tx) % ty == 0) or \
            (sx == tx and sy <= ty and (sy - ty) % tx == 0)
