class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        tmpr, tmpb = red, blue
        t1 = 1
        while red or blue:
            if red < t1:
                break
            red -= t1
            t1 += 1
            if blue < t1:
                break
            blue -= t1
            t1 += 1
        
        red, blue = tmpr, tmpb
        t2 = 1
        while red or blue:
            if blue < t2:
                break
            blue -= t2
            t2 += 1
            if red < t2:
                break
            red -= t2
            t2 += 1
        
        return max((t1 - 1),(t2 - 1))

        
        
        
test = Solution()
print(test.maxHeightOfTriangle(2,4))
