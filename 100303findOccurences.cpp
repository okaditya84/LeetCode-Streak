#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> occurrencesOfElement(std::vector<int>& nums, std::vector<int>& queries, int x) {
        std::unordered_map<int, std::vector<int>> bananaLocations;
        for (int i = 0; i < nums.size(); ++i) {
            bananaLocations[nums[i]].push_back(i);
        }
        
        std::vector<int> results;
        for (int query : queries) {
            if (bananaLocations[x].size() >= query) {
                results.push_back(bananaLocations[x][query - 1]);
            } else {
                results.push_back(-1);
            }
        }
        
        return results;
    }
};
