class Solution:
    def checkValidString(self, s: str) -> bool:
        open_stk = []
        star_stk = []

        for i, ch in enumerate(s):
            if ch == "(":
                open_stk.append(i)
            elif ch == "*":
                star_stk.append(i)
            else:
                if open_stk:
                    open_stk.pop()
                elif star_stk:
                    star_stk.pop()
                else:
                    return False
        
        while open_stk and star_stk:
            if star_stk[-1] < open_stk[-1]:
                return False
            star_stk.pop()
            open_stk.pop()

        return len(open_stk) == 0