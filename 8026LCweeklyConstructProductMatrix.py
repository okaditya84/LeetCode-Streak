class Solution:
  def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
    n = len(grid)
    m = len(grid[0])
    pro=1
     
     
    for i in range(n):
      for j in range(m):
        pro*= grid[i][j]

     
    p = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(n):w
      for j in range(m):
        p[i][j] = (pro//grid[i][j]) % 12345

    return p