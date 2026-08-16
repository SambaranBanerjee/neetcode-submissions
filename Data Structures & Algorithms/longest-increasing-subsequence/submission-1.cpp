class Solution {
private:
    vector<vector<int>> memo;
    int dfs(vector<int>& nums, int i, int prev) {
        if (i == nums.size()) {
            return 0;
        }
        
        if (memo[i][prev + 1] != -1) {
            return memo[i][prev + 1];
        }

        int exclude = dfs(nums, i + 1, prev);
        int include = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            include = 1 + dfs(nums, i + 1, i);
        }

        return memo[i][prev + 1] = max(exclude,include);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
        memo.assign(n , vector<int>(n + 1, -1));
        return dfs(nums, 0, -1);
    }
};
