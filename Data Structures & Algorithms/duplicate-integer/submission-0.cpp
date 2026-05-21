class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> dups;
        for(int num : nums){
            if(dups.find(num) == dups.end()){
                dups.insert(num);
            }
            else{
                return true;
            }
        }
        return false;
    }
};