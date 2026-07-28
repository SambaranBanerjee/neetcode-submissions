class Solution {
private:
    vector<vector<int>> result;
    void dfs(vector<int>& nums, int strIdx) {
        if (strIdx == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = strIdx; i < nums.size(); i++) {
            swap(nums[i], nums[strIdx]);
            dfs(nums, strIdx + 1);
            swap(nums[i], nums[strIdx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return result;
    }
};
