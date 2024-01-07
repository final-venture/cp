class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        index = 0

        while len(tokens) > 1:
            if tokens[index] in ["+", "-", "*", "/"]:
                tokens[index] = eval(f"math.trunc({tokens[index-2]}{tokens[index]}{tokens[index-1]})")
                tokens.pop(index-1)
                tokens.pop(index-2)
                index -= 1
                
            else:
                index += 1

        return int(tokens[0])
