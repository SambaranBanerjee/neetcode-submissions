class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""
        
        t_count = {}
        for ch in t:
            t_count[ch] = t_count.get(ch, 0) + 1
        
        formed, required = 0, len(t_count)

        s_count = {}
        start = 0

        res, res_len = [-1, -1], float("inf")
        for i in range(len(s)):
            s_count[s[i]] = s_count.get(s[i], 0) + 1

            if s[i] in t_count and s_count[s[i]] == t_count[s[i]]:
                formed += 1
            
            while formed == required:
                if i - start + 1 < res_len:
                    res = [start, i]
                    res_len = i - start + 1

                left_char = s[start]
                s_count[left_char] -= 1
                if left_char in t_count and s_count[left_char] < t_count[left_char]:
                    formed -= 1
                
                start += 1
            left, right = res
        return s[left : right + 1] if res_len != float("inf") else ""
            
            
            