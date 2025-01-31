class Solution {
    vector<vector<int>> DIRS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int label = 2;
        unordered_map<int, int> componentSize;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    componentSize[label] = dfs(grid, i, j, label);
                    label++;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    res = max(res, 1 + connect(grid, componentSize, i, j));
                }
            }
        }

        if (res == 0)
            return m * n;
            
        return res;
    }
    int dfs(vector<vector<int>>& grid, int r, int c, int label) {
        if (r < 0 || c < 0 || r == grid.size() || c == grid[0].size())
            return 0;
        if (grid[r][c] != 1)
            return 0;

        grid[r][c] = label;
        int res = 1;
        for (auto& d : DIRS) {
            int nr = r + d[0];
            int nc = c + d[1];
            res += dfs(grid, nr, nc, label);
        }
        return res;
    }
    int connect(vector<vector<int>>& grid, unordered_map<int, int>& componentSize, int r, int c) {
        unordered_set<int> seen = {};
        int area = 0;
        for (auto& d : DIRS) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr < 0 || nc < 0 || nr == grid.size() || nc == grid[0].size())
                continue;

            int index = grid[nr][nc];
            if (index > 1 && seen.count(index) == 0) {
                area += componentSize[index];
                seen.insert(index);
            }
        }
        return area;
    }
};
