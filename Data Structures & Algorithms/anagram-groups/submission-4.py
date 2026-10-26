class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        output = []
        seen = set()
        checkIndex = {}
        index = 0

        for word in strs:
            key = "".join(sorted(word))
            if key not in seen:
                seen.add(key)
                checkIndex[key] = index
                output.append([])
                index += 1
            output[checkIndex[key]].append(word)

        return output