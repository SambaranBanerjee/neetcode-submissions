class Solution {
private:
    vector<vector<int>> result;
    vector<int> current;

    void dfs(int i, vector<int>& nums, int target, int currSum) {
        if (currSum == target) {
            result.push_back(current);
            return;
        }
        if (i == nums.size() || currSum > target) {
            return;
        }

        currSum += nums[i];
        current.push_back(nums[i]);
        dfs(i, nums, target, currSum);
        currSum -= nums[i];
        current.pop_back();
        dfs(i + 1, nums, target, currSum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0,nums,target,0);
        return result;
    }
};
