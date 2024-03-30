#include <vector>
using namespace std;

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> prefix(n);

        if (possible[0] == 0) {
            possible[0] = -1;
        }
        prefix[0] = possible[0];

        for (int i = 1; i < n; i++) {
            if (possible[i] == 0) {
                possible[i] = -1;
            }
            prefix[i] = possible[i] + prefix[i - 1];
        }

        for (int i = 0; i < n - 1; i++) {
            int s1 = prefix[i];
            int s2 = prefix[n - 1] - prefix[i];
            if (s1 > s2) {
                return i + 1;
            }
        }

        return -1;
    }
};
