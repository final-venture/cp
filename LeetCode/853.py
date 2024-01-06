class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        stack = []
        cars = [[p, s] for p, s in zip(position, speed)]

        cars.sort(reverse=True)

        for p, s in cars:
            stack.append((target-p)/s)
            if len(stack) >= 2:
                if (target-p)/s <= stack[-2]:
                    stack.pop()
        
        return(len(stack))
