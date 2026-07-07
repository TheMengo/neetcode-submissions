class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int,int>> days; //Temp, day
        for(int i = 0; i < temperatures.size(); i++){
            int t = temperatures[i];
            while(!days.empty() && t > days.top().first){
                auto dpair = days.top();
                days.pop();
                res[dpair.second] = i - dpair.second;
            }
            days.push({t, i});
        }
        return res;
    }
};
