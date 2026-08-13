class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp_max(n),dp_min(n); //max and min product ending at index i
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < n; i++) {
            dp_max[i] = max({nums[i],nums[i] * dp_max[i - 1], nums[i] * dp_min[i - 1]});
            dp_min[i] = min({nums[i],nums[i] * dp_max[i - 1], nums[i] * dp_min[i - 1]});
            result = max(dp_max[i],result);
        }
        return result;
    }
};
