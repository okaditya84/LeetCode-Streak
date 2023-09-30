class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        #true if there are two dictinct indices i and j in the array such that nums[i]==nums[j] and abs(i-j)<=k
        # for i in range(len(nums)):
        #     for j in range(i+1,len(nums)):
        #         if nums[i]==nums[j] and abs(i-j)<=k and i!=j:
        #             return True

        #optimsed solution
        freq={}
        for i in range(len(nums)):
            if nums[i] in freq:
                if abs(i-freq[nums[i]])<=k:
                    return True
                else:
                    freq[nums[i]]=i
            else:
                freq[nums[i]]=i
        return False
        