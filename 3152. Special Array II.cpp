class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> parityIndex;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] % 2 ==  nums[i-1] % 2){
                parityIndex.push_back(i);
            }
        }
        vector<bool> res;
        for(auto& q : queries){
            bool bsResult = binarySearch(parityIndex, q[0] + 1, q[1]);
            res.push_back(bsResult);
        }
        return res;
    }
    bool binarySearch(vector<int>& parityIndex,int start, int end){
        int l = 0, r = parityIndex.size() - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(parityIndex[m] >= start && parityIndex[m] <= end){ 
                return false;
            }
            if(parityIndex[m] > end){
                r = m - 1;
            }
            else if(parityIndex[m] < start){
                l = m + 1;
            }
        }
        return true;
    }
};
