class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //value, indices
        unordered_map<int, int> search;
        for(int i = 0; i < nums.size(); i++){
            search[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(search.count(diff) && search[diff] != i){
                return {i, search[diff]};
            }
        }
        return {};
    }
};
