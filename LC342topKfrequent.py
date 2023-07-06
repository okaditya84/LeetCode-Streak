class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #count the frequency of each element and store it in a dictionary
        freq = {}
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        #find the k most frequent elements
        #use a heap to store the k most frequent elements
        heap = []
        for key, value in freq.items():
            if len(heap) < k:
                heapq.heappush(heap, (value, key))
            else:
                heapq.heappushpop(heap, (value, key))
        #return the k most frequent elements
        return [key for value, key in heap]
        