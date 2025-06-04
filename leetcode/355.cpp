class Twitter
{
private:
    unordered_map<int, unordered_set<int>> follows{};
    priority_queue<vector<int>> tweets{};

public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        static int timeId = 0;
        vector<int> tweet{timeId++, userId, tweetId};
        tweets.push(tweet);
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        priority_queue<vector<int>> pq = tweets;
        while (!pq.empty() && res.size() < 10)
        {
            vector<int> cand_tweet = pq.top();
            if (cand_tweet[1] == userId || follows[userId].find(cand_tweet[1]) != follows[userId].end())
            {
                res.push_back(cand_tweet[2]);
            }
            pq.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId)
    {
        if (follows.find(followerId) == follows.end())
        {
            unordered_set<int> st{};
            follows[followerId] = st;
        }
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (follows.find(followerId) != follows.end())
        {
            auto &x = follows[followerId];
            if (x.find(followeeId) != x.end())
                x.erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
