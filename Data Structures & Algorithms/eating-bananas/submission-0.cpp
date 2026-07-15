class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        sort(piles.rbegin(), piles.rend());
        int r = piles[0];
        int res = r;
        while(l <= r){
            int m = (l + r) / 2;
            int tt = 0;
            for(int i = 0; i < piles.size(); i++){
                if(m >= piles[i]){
                    tt += piles.size() - i;
                    break;
                }else{
                    tt += ceil(static_cast<double>(piles[i]) / m);
                }
            }
            if(tt <= h){
                res = m;
                r = m -1;
            }else{
                l = m + 1;
            }
            
        }
        return res;
    }
};
