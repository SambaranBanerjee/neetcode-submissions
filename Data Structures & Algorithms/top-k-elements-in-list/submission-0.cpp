class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        priority_queue<pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>>> minHeap;
        
        for (const auto& pair : frequencyMap) {
            minHeap.push({pair.second, pair.first});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
