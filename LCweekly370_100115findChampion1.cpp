class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            bool flag=1;
            for(int j=0;j<n;j++){
                if(i!=j&&grid[j][i]==1){
                    flag=0;
                    break;

                }
            }
            if(flag) return i;

        }
        return -1;
    }
};