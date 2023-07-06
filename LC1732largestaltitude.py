class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        output=[]
        output.append(0)
        for i in range(len(gain)):
            output.append(output[i]+gain[i])
        return max(output)
        