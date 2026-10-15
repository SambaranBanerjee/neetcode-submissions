class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""

        t_count = {}
        for i in t:
            t_count[i] = t_count.get(i, 0) + 1

        window = {}

        required = len(t_count)
        formed = 0

        res, res_len = [-1, -1], float("inf")

        start = 0
        for i in range(len(s)):
            right_char = s[i]
            window[right_char] = window.get(right_char, 0) + 1            

            if right_char in t_count and window[right_char] == t_count[right_char]:
                formed += 1
            
            while formed == required:
                if i - start + 1 < res_len:
                    res = [start, i]
                    res_len = i - start + 1

                left_char = s[start]
                window[left_char] -= 1

                if left_char in t_count and window[left_char] < t_count[left_char]:
                    formed -= 1

                start += 1

        left, right = res
        return s[left : right + 1] if res_len != float("inf") else ""
        
