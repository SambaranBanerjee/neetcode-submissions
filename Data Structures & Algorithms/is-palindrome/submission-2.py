class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleaned_text = "".join([char for char in s if char.isalnum()])
        cleaned_text = cleaned_text.lower()
        i = 0
        j = len(cleaned_text) - 1
        while (i < j):
            if (cleaned_text[i] != cleaned_text[j]):
                return False
            i += 1
            j -= 1

        return True