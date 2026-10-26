class Twitter {
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> tweets; // user -> (time, id)
    unordered_map<int, unordered_set<int>> follows;
public:
    Twitter() {}
    void postTweet(int userId, int tweetId) { tweets[userId].emplace_back(time++, tweetId); }
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> all;
        auto add = [&](int u) { auto& v = tweets[u]; for (int i = max(0, (int)v.size() - 10); i < (int)v.size(); i++) all.push_back(v[i]); };
        add(userId);
        for (int f : follows[userId]) if (f != userId) add(f);
        sort(all.rbegin(), all.rend());
        vector<int> res;
        for (int i = 0; i < (int)all.size() && i < 10; i++) res.push_back(all[i].second);
        return res;
    }
    void follow(int followerId, int followeeId) { follows[followerId].insert(followeeId); }
    void unfollow(int followerId, int followeeId) { follows[followerId].erase(followeeId); }
};