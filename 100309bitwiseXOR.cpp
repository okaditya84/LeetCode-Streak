#include <vector>
#include <unordered_map>

class Solution {
public:
    int duplicateNumbersXOR(std::vector<int>& nums) {
        std::unordered_map<int, int> bananaCounter;
        for (int banana : nums) {
            bananaCounter[banana]++;
        }
        
        int xorOfClones = 0;
        bool foundClones = false;

        for (const auto& pair : bananaCounter) {
            if (pair.second == 2) {
                xorOfClones ^= pair.first;
                foundClones = true;
            }
        }
        
        return foundClones ? xorOfClones : 0;
    }
};
