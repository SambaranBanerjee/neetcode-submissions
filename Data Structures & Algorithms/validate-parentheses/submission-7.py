class Solution:
    def isValid(self, s: str) -> bool:
        bracket_map = {")": "(", "}": "{", "]": "["}
        stack = []

        for ch in s:
            if ch in bracket_map:
                top_element = stack.pop() if stack else "$"
                if bracket_map[ch] != top_element:
                    return False
            else:
                stack.append(ch)
        
        return len(stack) == 0