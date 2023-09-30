class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n=len(nums)
        leftSum=[0]*n
        rightSum=[0]*n
        answer=[0]*n
        leftSum[0]=nums[0]
        rightSum[n-1]=nums[n-1]
        for i in range(1,n):
            leftSum[i]=leftSum[i-1]+nums[i]
        for i in range(n-2,-1,-1):
            rightSum[i]=rightSum[i+1]+nums[i]
        for i in range(n):
            answer[i]=leftSum[i]-rightSum[i]
        return answer
        