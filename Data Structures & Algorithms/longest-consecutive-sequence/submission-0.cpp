class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }

        int n = nums.size();
        int longestLength = 0;
        for (int i = 0; i < n; i++) {
            if (st.find(nums[i] - 1) == st.end()) {
                int current = nums[i];
                int length = 1;
                while (st.find(current + 1) != st.end()) {
                    current = current + 1;
                    length++;
                }
                longestLength = max(longestLength, length);
            }
        }
        return longestLength;
    }
};
