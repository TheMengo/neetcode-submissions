class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        // key: unique int, value: the number of times its seen
        unordered_map<int, int> num_map;
        for(auto num : nums){
            num_map[num]++;
        }
        vector<pair<int,int>> arr;
        for(auto num : num_map){
            arr.push_back({num.second, num.first});
        }
        sort(arr.rbegin(), arr.rend());
        for(int i = 0; i < k; i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};
