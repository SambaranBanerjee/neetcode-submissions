class Solution {
private:
    vector<vector<int>> memo;
    bool dfs (vector<int>& nums,int i, int target) {
        if (target == 0) {
            return true;
        }
        if (i == nums.size() || target < 0) {
            return false;
        }
        if (memo[i][target] != -1) {
            return memo[i][target];
        }

        bool exclude = dfs(nums, i + 1, target);
        bool include = false;
        if (nums[i] <= target) {
            include = dfs(nums, i + 1, target - nums[i]);
        }

        return memo[i][target] = (include || exclude);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        if (totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum / 2;
        memo.assign(n,vector<int>(target + 1, -1));
        return dfs(nums,0,target);
    }
};
