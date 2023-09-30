class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        for i in range(0,n):
            for j in nums:
                if i==j:
                    break
            else:
                return i
        return n
        