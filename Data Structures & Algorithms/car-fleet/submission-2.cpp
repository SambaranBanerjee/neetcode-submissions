class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
        vector<double> time(n, 0);
        vector<pair<int,int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i],speed[i]};
        }
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        for (int i = 0; i < n; i++) {
            time[i] = (double)(target - cars[i].first) / cars[i].second;
        }
        double max_time = time[0];
        int fleet = 1;
        for (int i = 1; i < n ; i++) {
            if (time[i] > max_time) {
                fleet++;
                max_time = time[i];
            }
        }
        return fleet;
    }
};
