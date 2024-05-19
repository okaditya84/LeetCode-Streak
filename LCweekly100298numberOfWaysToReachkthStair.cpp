#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  int waysToReachStair(int k) {
    const int MOD = 1e9 + 7;
    if (k == 0) return 2;

    // Corrected calculation for maxJump
    int maxJump = log2(k + 1); 
    vector<long long> dp(k + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= k; ++i) {
      dp[i] = dp[i - 1];
      for (int j = 2; j <= maxJump; ++j) {
        if (i >= (1 << (j - 1))) {
          dp[i] = (dp[i] + dp[i - (1 << (j - 1))]) % MOD;
        }
      }
    }

    return dp[k];
  }
};
