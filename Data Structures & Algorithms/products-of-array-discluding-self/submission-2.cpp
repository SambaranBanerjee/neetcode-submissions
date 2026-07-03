class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        int zeroCount = 0;

        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
            }
            else {
                totalProduct *= num;
            }
        }

        vector<int> result(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 1) {
                result[i] = 0;
            }
            else if (zeroCount == 1) {
                result[i] = (nums[i] == 0) ? totalProduct : 0;
            }
            else {
                result[i] = totalProduct / nums[i];
            }
        }

        return result;
    }
};
