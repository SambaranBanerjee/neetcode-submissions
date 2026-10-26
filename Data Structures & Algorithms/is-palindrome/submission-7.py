class Solution:
    def isPalindrome(self, s: str) -> bool:
        word = s.lower()
        word = "".join(char for char in word if char.isalnum())

        l = 0
        r = len(word) - 1

        while l <= r:
            if word[l] != word[r]:
                return False
            l += 1
            r -= 1

        return True