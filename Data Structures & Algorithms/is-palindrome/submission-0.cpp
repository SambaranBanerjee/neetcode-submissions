class Solution {
public:
    bool isPalindrome(string s) {
        string new_str1;
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                new_str1.push_back(tolower(s[i]));
            }
        }
        string new_str2 = new_str1;
        int start = 0;
        int end = new_str1.length() - 1;
        while (start < end) {
            swap(new_str2[start], new_str2[end]);
            start++;
            end--;
        }
        return new_str1 == new_str2 ? true : false;
    }
};
