class Solution:
    def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
        good_indices=[]
        for i, var in enumerate(variables):
            a,b,c,m=var
            if((a**b%10)**c)%m==target:
                good_indices.append(i)
        return good_indices
                
                
        