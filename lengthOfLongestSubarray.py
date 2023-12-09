class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        i = 0
        j = 0
        n = len(nums)
        ump = defaultdict(int)
        ans = 0

        while j < n:
            ump[nums[j]] += 1
            if ump[nums[j]] > k:
                while i < j and ump[nums[j]] > k:
                    if ump[nums[i]] == 1:
                        del ump[nums[i]]
                    else:
                        ump[nums[i]] -= 1
                    i += 1
            ans = max(ans, j - i + 1)
            j += 1
        return ans
