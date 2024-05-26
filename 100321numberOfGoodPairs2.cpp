#include <vector>
#include <unordered_map>
#include <cmath>

class Solution {
public:
    long long numberOfPairs(std::vector<int>& bananaPile1, std::vector<int>& bananaPile2, int monkeyCount) {
        std::unordered_map<int, int> jungleMap;
        long long happyMonkeys = 0;

        for (int banana : bananaPile2) {
            jungleMap[banana]++;
        }

        for (int coconut : bananaPile1) {
            if (coconut % monkeyCount == 0) {
                int targetBanana = coconut / monkeyCount;
                for (int factor = 1; factor * factor <= targetBanana; factor++) {
                    if (targetBanana % factor == 0) {
                        happyMonkeys += (long long) jungleMap[factor];
                        if (factor != targetBanana / factor) {
                            happyMonkeys += (long long) jungleMap[targetBanana / factor];
                        }
                    }
                }
            }
        }

        return happyMonkeys;
    }
};