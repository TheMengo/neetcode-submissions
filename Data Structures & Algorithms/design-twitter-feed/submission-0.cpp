class Twitter {
private:
    int count;

    // key: userID -> value: timestamp & tweetId
    unordered_map<int, vector<pair<int,int>>> tweetMap;

    // key: userID -> value: set of followers
    unordered_map<int, unordered_set<int>> follows;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count, tweetId});
        if(tweetMap[userId].size() > 10){
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
        count--;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        follows[userId].insert(userId);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        if(follows[userId].size() >= 10){
            priority_queue<vector<int>> maxHeap;
            for(auto f: follows[userId]){
                if(!tweetMap.count(f)){
                    continue;
                }
                int idx = tweetMap[f].size() - 1;
                auto &p = tweetMap[f][idx];
                maxHeap.push({-p.first, p.second, f, idx -1});

                // We only look at the top 10 posts
                if(maxHeap.size() > 10){
                    maxHeap.pop();
                }
            }
            while(!maxHeap.empty()){
                auto t = maxHeap.top();
                maxHeap.pop();
                minHeap.push({-t[0], t[1], t[2], t[3]});
            }
        }
        else{
            for(auto f: follows[userId]){
                if(!tweetMap.count(f)){
                    continue;
                }
                int idx = tweetMap[f].size() -1;
                auto &p = tweetMap[f][idx];
                minHeap.push({p.first, p.second, f, idx - 1});
            }

        }
        while(!minHeap.empty() && res.size() < 10){
            auto t = minHeap.top();
            minHeap.pop();
            res.push_back(t[1]);
            int idx = t[3];
            if(idx >= 0 ){
                auto &p = tweetMap[t[2]][idx];
                minHeap.push({p.first, p.second, t[2], idx - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(follows[followerId].count(followeeId)){
            follows[followerId].erase(followeeId);
        }
        
    }
};
