class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        tmp = []
        for i in range(n):
            sum = nums[i]
            tmp.append(sum)
            for j in range(i+1, n):
                sum += nums[j]
                tmp.append(sum)
        
        tmp.sort()
        ans = 0
        mod = 10**9 + 7
        for i in range(left-1, right):
            ans = (ans + tmp[i]) % mod
        return ans