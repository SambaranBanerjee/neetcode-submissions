class Solution:

    def encode(self, strs: List) -> str:
        result = "" 
        for s in strs:
            result += str(len(s)) + "#" + s
        return result
        
    def decode(self, s: str) -> List[str]:
        result = []
        start = 0
        while start < len(s):
            j = start
            while s[j] != "#":
                j += 1
            
            length = int(s[start:j])
            str_start = j + 1
            str_end = str_start + length

            result.append(s[str_start:str_end])

            start = str_end

            
        return result
