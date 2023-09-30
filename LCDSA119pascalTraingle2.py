class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        for i in range(rowIndex+1):
            if i==0:
                ans=[1]
            elif i==1:
                ans.append(1)
            else:
                ans.append(1)
                for j in range(i-1,0,-1):
                    ans[j]=ans[j]+ans[j-1]
        return ans
        