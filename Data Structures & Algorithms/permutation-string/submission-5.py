class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        s1_count = {}
        s2_count = {}

        for i in range(len(s1)):
            s1_count[s1[i]] = s1_count.get(s1[i], 0) + 1
            s2_count[s2[i]] = s2_count.get(s2[i], 0) + 1

        if s1_count == s2_count:
            return True

        for i in range(len(s1), len(s2)):
            right_char = s2[i]
            s2_count[right_char] = s2_count.get(right_char, 0) + 1

            left_char = s2[i - len(s1)]
            s2_count[left_char] -= 1

            if s2_count[left_char] == 0:
                del s2_count[left_char]

            if s1_count == s2_count:
                return True

        return False