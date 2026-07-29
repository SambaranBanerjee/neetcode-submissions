class Solution {
private:
    vector<vector<int>> result;
    vector<int> current;

    void dfs(vector<int>& nums, int strIdx) {
        result.push_back(current);
        for (int i = strIdx; i < nums.size(); i++) {
            if (i > strIdx && nums[i] == nums[i - 1]) {
                continue;
            }
            current.push_back(nums[i]);
            dfs(nums,i + 1);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return result;
    }
};
