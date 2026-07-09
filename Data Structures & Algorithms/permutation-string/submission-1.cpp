class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> s1Count (26, 0);
        vector<int> s2Count (26, 0);
        
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            s1Count[s1[i] - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            s2Count[s2[i] - 'a']++;
        }
        if (s1Count == s2Count) {
            return true;
        }
        for (int i = n; i < s2.size(); i++) {
            s2Count[s2[i] - 'a']++;
            s2Count[s2[i - n] - 'a']--;
            if (s1Count == s2Count) {
                return true;
            }
        }
        return false;
    }
};
