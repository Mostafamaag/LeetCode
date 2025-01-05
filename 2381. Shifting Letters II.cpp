class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> range(n+1);
        for(auto sh : shifts){
            int shift = sh[2] == 1? 1 : -1;
            range[sh[0]] += shift;
            range[sh[1]+1] -= shift;
        }
        int shift_val = 0;
        for(int i = 0; i < n; i++){
            shift_val = (shift_val + range[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + shift_val + 26) % 26;
        }
        return s;
    }
};
