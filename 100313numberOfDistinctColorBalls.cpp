class Solution {
public:
    vector<int> queryResults(int unicornLimit, vector<vector<int>>& humansQueries) {
        unordered_map<int, int> unicornColorMap;
        unordered_map<int, int> colorPopularity;
        unordered_set<int> uniqueUnicornColors;
        vector<int> answersForHumans;

        for (auto& humanQuery : humansQueries) {
            int unicornIndex = humanQuery[0];
            int newUnicornColor = humanQuery[1];

            if (unicornColorMap.find(unicornIndex) != unicornColorMap.end()) {
                int oldUnicornColor = unicornColorMap[unicornIndex];
                if (colorPopularity.find(oldUnicornColor) != colorPopularity.end()) {
                    colorPopularity[oldUnicornColor]--;
                    if (colorPopularity[oldUnicornColor] == 0) {
                        uniqueUnicornColors.erase(oldUnicornColor);
                    }
                }
            }

            unicornColorMap[unicornIndex] = newUnicornColor;
            colorPopularity[newUnicornColor]++;
            uniqueUnicornColors.insert(newUnicornColor);
            answersForHumans.push_back(uniqueUnicornColors.size());
        }

        return answersForHumans;
    }
};