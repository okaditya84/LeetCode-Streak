class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        #delete one element to get the longest subarray of 1s
        #use a sliding window to find the longest subarray of 1s


        #edge case
        if len(nums) == 1:
            return 0

        #initialize the left and right pointers
        left = 0
        right = 0

        #initialize the longest subarray length
        longest = 0

        #initialize the number of 0s
        numZeros = 0

        #iterate through the array

        while right < len(nums):
            #if the current number is 0, increment the number of 0s
            if nums[right] == 0:
                numZeros += 1

            #if the number of 0s is greater than 1, increment the left pointer and decrement the number of 0s
            while numZeros > 1:
                if nums[left] == 0:
                    numZeros -= 1
                left += 1

            #update the longest subarray length
            longest = max(longest, right - left)

            #increment the right pointer
            right += 1

        #return the longest subarray length
        return longest

        