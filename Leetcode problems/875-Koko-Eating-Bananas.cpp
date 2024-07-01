class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        int k = 0;
        while(l <= r){
            int mid = (r+l)/2;
            if(canSheEat(mid, piles, h)){
                r = mid-1;
                k = mid;
            }
            else{
                l = mid+1;
            }
        }
        return k;
    }
    bool canSheEat(int mid, vector<int> piles, int h){
        long long temp_h = 0;
        for(int num : piles){
            temp_h += (num + mid - 1) / mid;
        }
        if(temp_h > h){
            return false;
        }
        else{
            return true;
        }
    }
};