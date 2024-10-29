class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        r = len(grid)
        c =  len(grid[0])
        dp = [[-1] * c for _ in range(r)]
        
        def dfs(i, j, prev):
            if i < 0 or i >= r or j >= c or prev >= grid[i][j]:
                return 0
            if dp[i][j] != -1:
                return dp[i][j]

            dp[i][j] = 1 + max(
                dfs(i - 1, j + 1, grid[i][j]),
                dfs(i, j + 1, grid[i][j]),
                dfs(i + 1, j + 1, grid[i][j])
            )
            return dp[i][j] 
            
        res = 0
        for i in range(r):
            res = max(res, dfs(i, 0, -1) - 1)
        
        return res
