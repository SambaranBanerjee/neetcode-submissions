class Solution {
public:
    bool isPossible(int mid, vector<int>& piles, int h) {
        int totalHours = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalHours += (piles[i] + mid - 1) / mid;
        }
        if (totalHours <= h) {
            return true;
        }
        else {
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MAX;
        int result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(mid, piles, h)) {
                result = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return result;
    }
};
