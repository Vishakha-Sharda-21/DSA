class Twitter {
    struct Tweet {
        int id;
        int time;
        
        Tweet(int id, int time) : id(id), time(time) {}
    };

    int timestamp = 0;

    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> followings;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, timestamp++});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        priority_queue<
            pair<int, int>
        > pq;

        // Own tweets
        for (int i = 0; i < tweets[userId].size(); i++) {
            pq.push({tweets[userId][i].time, tweets[userId][i].id});
        }

        // Followed users' tweets
        for (int followee : followings[userId]) {
            for (int i = 0; i < tweets[followee].size(); i++) {
                pq.push({tweets[followee][i].time, tweets[followee][i].id});
            }
        }

        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};
