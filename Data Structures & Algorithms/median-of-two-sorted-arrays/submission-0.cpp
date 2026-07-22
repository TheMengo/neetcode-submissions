class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        vector<int>& a = nums1;
        vector<int>& b = nums2;
        int total = a.size() + b.size();
        int half = (total + 1) / 2;

        int l = 0;
        int r = a.size();
        while(l <= r){
            int i = (l + r) / 2;
            int j = half - i;

            int aleft = i > 0 ? a[i - 1] : INT_MIN;
            int aright = i < a.size() ? a[i] : INT_MAX;
            int bleft = j > 0 ? b[j - 1] : INT_MIN;
            int bright = j < b.size() ? b[j] : INT_MAX;

            if(aleft <= bright && bleft <= aright){
                if(total % 2 != 0){
                    return max(aleft, bleft);
                }

                return (max(aleft, bleft) + min(aright, bright)) / 2.0;

            } else if(aleft > bright){
                r = i - 1;
            }else{
                l = i + 1;
            }
        }
        return -1;
    }
};
