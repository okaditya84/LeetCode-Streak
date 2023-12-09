class Solution {
    const int INF=1e9;
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans=0;
        for (int mask=0; mask<(1<<n);mask++){
            unordered_set<int> c;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    c.insert(i);
                }
            }
            vector<vector<int>> dp(n,vector<int>(n,INF));
            for(auto& i: roads){
                if(c.count(i[0])&& c.count(i[1])){
                    int v=min(i[2],dp[i[0]][i[1]]);
                    dp[i[0]][i[1]]=dp[i[1]][i[0]]=v;
                }
            }
            for(int i=0;i<n;i++){
                dp[i][i]=0;
            }
            for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                        
                    }
                }
            }
            bool ok=true;
            for(int i:c){
                for(int  j:c){
                    if(dp[i][j]>maxDistance){
                        ok=false;
                        break;
                    }
                }
                if(!ok) break;
                
            }
            ans+=ok;
        }
        return ans;
    }
};