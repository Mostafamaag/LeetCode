class Solution {
    vector<vector<int>> DIRS = { {1,0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> res(m, vector(n, -1));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(auto &d : DIRS){
                int nr = r + d[0];
                int nc = c + d[1];
                if(!isValid(nr, nc, m, n) || res[nr][nc] != -1) continue;
                res[nr][nc] = res[r][c] + 1;
                q.push({nr, nc});
            }
        }
        return res;
    }
    bool isValid(int row, int col, int m, int n){
        if(row < m && col < n && row >= 0 && col >= 0) return true;
        return false;
    }
};
