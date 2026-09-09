class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        output = []
        seen = set()
        checkIndex = {}
        index = 0
        for i in strs:
            key = "".join(sorted(i))
            if key not in seen:
                seen.add(key)
                checkIndex[key] = index
                output.append([])
                index += 1
            
            output[checkIndex[key]].append(i)
        return output