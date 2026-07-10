class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }    
        int n = s.size();
        vector<int> sCount(128,0);
        vector<int> tCount(128,0);

        int formed = 0;
        int required = 0;
        int minLen = INT_MAX;

        for (int i = 0; i < t.size(); i++) {
            tCount[t[i]]++;
        }

        for (int i = 0; i < tCount.size(); i++) {
            if (tCount[i] != 0) {
                required++;
            }
        }

        int startIdx = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            sCount[s[right]]++;
            if (sCount[s[right]] == tCount[s[right]]) {
                formed++;
            }
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }
                sCount[s[left]]--;
                if (sCount[s[left]] < tCount[s[left]]) {
                    formed--;
                }
                left++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
