class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++) {
            int complement = target - numbers[i];
            for (int j = i; j < numbers.size(); j++) {
                if (numbers[j] == complement && numbers[j] != numbers[i]) {
                    return {i+1,j+1};
                }
            }
        }
        return {};
    }
};
