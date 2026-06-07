class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numl = nums.size();
        vector<int> res(numl, 1);
        for(int i = 1; i < numl; i++){
            // current prefix = last prefix * last number
            // e.g 1,2,3,4
            // res[1] = res[0](1) * nums[0](1)
            // res[2] = res[1](1)  * nums[1](2)
            res[i] = res[i - 1] * nums[i - 1];
        }
        // Iterate backwards
        int postfix = 1;
        for(int i = numl - 1; i >= 0; i--){
            res[i] *= postfix;
            // Postfix will start at 1, and multiply backwards
            // This works bc the postfix will always be accurate 
            // based on the position of the vector
            postfix *= nums[i];
        }
        return res;
    }
};
