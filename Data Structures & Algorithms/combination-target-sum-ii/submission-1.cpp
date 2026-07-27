class Solution {
private:
    vector<vector<int>> result;
    vector<int> current;

    void dfs(int startIdx, vector<int> candidates, int target) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = startIdx; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }

            if (i > startIdx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            current.push_back(candidates[i]);
            dfs(i + 1, candidates, target - candidates[i]);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0,candidates, target);
        return result;
    }
};
