class Twitter {
public:
    int time = 0;

    unordered_map<int, vector<pair<int,int>>> mpUser;  
    // user → {timestamp, tweetId}

    unordered_map<int, unordered_set<int>> mpFollower;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        mpUser[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq; 

        for (auto &t : mpUser[userId]) {
            pq.push(t);
        }

        for (auto &followee : mpFollower[userId]) {
            for (auto &t : mpUser[followee]) {
                pq.push(t);
            }
        }

        vector<int> ans;

        for (int i = 0; i < 10 && !pq.empty(); i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)   // avoid self duplicate
            mpFollower[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        mpFollower[followerId].erase(followeeId);
    }
};