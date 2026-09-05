class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k < 1 && n <= 1) return 0;
        vector<int>pref(n);
        vector<int>suff(n);
        pref[0] = nums[0];
        suff[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], nums[i]);
        }
           
        for(int s = n - 2; s >= 0; s--) {
            suff[s] = min(suff[s + 1], nums[s]);
        }

        for(int j = 0; j < n; j++){
            if((pref[j] - suff[j]) <= k){
                return j;
            }
        }

        return -1;
    }
};