class Solution {
public:
    struct CoordComp{
        bool operator()(const vector<int>& p1, const vector<int>& p2){
            int p1Dist = p1[0] * p1[0] + p1[1] * p1[1];
            int p2Dist = p2[0] * p2[0] + p2[1] * p2[1];
            return p1Dist > p2Dist;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>,vector<vector<int>>, CoordComp> pq(points.begin(), points.end());

        while(k > 0){
            res.push_back(pq.top());
            pq.pop();
            k--;
        }
        return res;
    }
};
