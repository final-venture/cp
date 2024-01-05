class Solution:
    def isValid(self, s: str) -> bool:
        stack = [0]
        for bracket in s:
            if bracket == "(" or bracket == "[" or bracket == "{":
                stack.append(bracket)
            if bracket == ")":
                if stack[-1] != "(":
                    return False
                stack.pop()
            if bracket == "]":
                if stack[-1] != "[":
                    return False
                stack.pop()
            if bracket == "}":
                if stack[-1] != "{":
                    return False
                stack.pop()
                
        if stack == [0]:
            return True
        return False
