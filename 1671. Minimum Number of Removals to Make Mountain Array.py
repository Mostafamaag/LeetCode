class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)

        lis = [1] * n
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    lis[i] = max(lis[i], 1 + lis[j])

        lds = [1] * n
        for i in reversed(range(n)):
            for j in range(i+1, n):
                if(nums[j] < nums[i]):
                    lds[i] = max(lds[i], 1 + lds[j])

        res = n
        for i in range(1, n - 1):
            if lis[i] > 1 < lds[i]:
                res = min(res, n - lis[i] - lds[i] + 1)

        return res