class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> visited;
        return dfs(s, 0 , visited);
    }
    int dfs(string s, int i, unordered_set<string> &visited){
        
        string tmp = "";
        int res = 0;
        for(int j = i; j < s.size(); j++){
            tmp += s[j];
            if(!visited.contains(tmp)){
                visited.insert(tmp);
                res = max(res, 1 + dfs(s, j+1, visited));
                visited.erase(tmp);
            }
        }
        return res;
    }
};
