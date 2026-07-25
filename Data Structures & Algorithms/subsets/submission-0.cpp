class Solution {
private:
    vector<vector<int>>result;
    vector<int> current;

    void dfs(int i, vector<int>& nums) {
        if (i == nums.size()) {
            result.push_back(current);
            return;
        }

        current.push_back(nums[i]);
        dfs(i + 1, nums);

        current.pop_back();

        dfs(i + 1, nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return result;
    }
};
