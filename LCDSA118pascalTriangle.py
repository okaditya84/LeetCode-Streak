class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        for i in range(numRows):
            if i==0:
                ans=[[1]]
            elif i==1:
                ans.append([1,1])
            else:
                ans.append([1])
                for j in range(1,i):
                    ans[i].append(ans[i-1][j-1]+ans[i-1][j])
                ans[i].append(1)
        return ans
        