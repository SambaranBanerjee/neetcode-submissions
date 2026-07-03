class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& str : strs) {
            string sortedKey = str;
            sort(sortedKey.begin(), sortedKey.end());
            anagramGroups[sortedKey].push_back(str);
        }    

        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        return result;
    }
};
