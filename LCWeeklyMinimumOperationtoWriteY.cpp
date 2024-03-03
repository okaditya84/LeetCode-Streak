#include <vector>
#include <climits>

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int m = n / 2;
        vector<int> ydig(3, 0);
        int i = 0, j = 0;

        // Traverse diagonally from top-left to middle
        while (i < m && j < m) {
            ydig[grid[i][j]]++;
            vis[i][j]++;
            i++;
            j++;
        }

        i = 0;
        j = n - 1;

        // Traverse diagonally from top-right to middle
        while (i < m && j > m) {
            ydig[grid[i][j]]++;
            vis[i][j]++;
            i++;
            j--;
        }

        // Traverse vertically in the middle column
        for (int i = m; i < n; i++) {
            ydig[grid[i][m]]++;
            vis[i][m]++;
        }

        vector<int> other(3, 0);

        // Traverse the remaining cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0)
                    other[grid[i][j]]++;
            }
        }

        int ans = INT_MAX;

        // Consider different combinations of digits
        ans = min(ans, ydig[1] + ydig[2] + other[0] + other[2]);
        ans = min(ans, ydig[1] + ydig[2] + other[0] + other[1]);
        ans = min(ans, ydig[0] + ydig[2] + other[0] + other[1]);
        ans = min(ans, ydig[0] + ydig[2] + other[2] + other[1]);
        ans = min(ans, ydig[0] + ydig[1] + other[0] + other[2]);
        ans = min(ans, ydig[0] + ydig[1] + other[1] + other[2]);

        return ans;
    }
};
