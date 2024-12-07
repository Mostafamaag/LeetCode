class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end()), res = 0;
        while(l <= r){
            int m = l + (r - l) / 2;
            int ops = 0;
            for(auto n : nums){
                if(n > m){
                    ops += ceil((double)n/m - 1);
                }
            }

            if(ops > maxOperations) l = m + 1; 
            else{
                r = m - 1;
                res = m;
            };
        }

        return res;
    }
};
