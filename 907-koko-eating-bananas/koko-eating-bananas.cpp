class Solution {
public:
    bool canFinish(vector<int>& piles, int mid, int h){
        long long rate = 0;
        for(int x : piles){
            rate += (x + (long long)mid - 1) / mid;
        }
        return rate <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canFinish(piles, mid, h)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};