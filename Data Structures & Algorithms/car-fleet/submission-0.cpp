class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i =0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        vector<double> car_stack;
        for(auto& p: cars){
            car_stack.push_back((double)(target - p.first) / p.second);
            if(car_stack.size() >= 2 &&
             car_stack.back() <= car_stack[car_stack.size() - 2] ){
                car_stack.pop_back();
            }
        }
        return car_stack.size();
    }
};
