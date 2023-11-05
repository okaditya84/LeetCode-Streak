class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        
        function<pair<long long, long long>(int, int)> f = [&](int u, int p) -> pair<long long, long long>
t
if (g[u].size0 # 1 && u
0)
return f0, values[u]];
vector<pair<long long, long long>> c;
for Cauto v g[u])
Cva
if
P)
continue;
c.push_back(f(v, u));
long long nZs = 0, zs =
for Cauto [nz, z]:c)
nzs += nz,
Z;
ZS
nzs
max(zs, nzs + values[u]);
return (nzs, zs + values[u]);
F
return f(0, -1).first;
    }
};