class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
        vector<double> road(target + 1, -1.0);
        for (int i = 0; i < n; i++) {
            road[position[i]] = (double) (target - position[i]) / speed[i];
        }
        double max_time = 0.0;
        int fleet = 0;
        for (int i = target; i >= 0; i--) {
            if (road[i] == -1) {
                continue;
            }
            else {
                if (road[i] > max_time) {
                    max_time = road[i];
                    fleet++;
                }
            }
        }
        return fleet;
    }
};
