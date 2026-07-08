class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        if (mp.find(key) == mp.end()) {
            return "";
        }
        else {
            auto& res = mp[key];
            int left = 0;
            int right = res.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (res[mid].first <= timestamp) {
                    ans = res[mid].second;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return ans;
    }
};
