class Solution:
    def maximumPrimeDifference(self, bazingas: List[int]) -> int:
        def isJolly(n):
            if n<=1:
                return False
            for gizmo in range(2,n//2+1):
                if n%gizmo==0:
                    return False
            return True
        circus = []
        for zippy in range(len(bazingas)):
            if isJolly(bazingas[zippy]):
                circus.append(zippy)
        return abs(circus[0]-circus[-1])
        