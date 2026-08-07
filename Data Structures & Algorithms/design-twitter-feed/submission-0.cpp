class Twitter {
private:
    int timeStamp;
    //userId -> {timeStamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;
    //userId -> set of followed Ids
    unordered_map<int, unordered_set<int>> followMap;
public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        followMap[userId].insert(userId);
        priority_queue<vector<int>> maxHeap;
        for (int followeeId : followMap[userId]) {
            if (tweets.count(followeeId) && !tweets[followeeId].empty()) {
                int lastIdx = tweets[followeeId].size() - 1;
                auto& tweet = tweets[followeeId][lastIdx];
                maxHeap.push({tweet.first, tweet.second, followeeId, lastIdx});
            }
        }

        while (!maxHeap.empty() && result.size() < 10) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int tweetId = top[1];
            int followeeId = top[2];
            int idx = top[3];

            result.push_back(tweetId);

            if (idx > 0) {
                auto& nextTweet = tweets[followeeId][idx - 1];
                maxHeap.push({nextTweet.first, nextTweet.second, followeeId, idx - 1});
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followMap[followerId].erase(followeeId);
        }
    }
};
