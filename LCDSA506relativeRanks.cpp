class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> m;
        for (int i = 0; i < score.size(); ++i) {
            m[score[i]] = i;
        }
        sort(score.begin(), score.end(), greater<int>());
        vector<string> res(score.size());
        for (int i = 0; i < score.size(); ++i) {
            if (i == 0) res[m[score[i]]] = "Gold Medal";
            else if (i == 1) res[m[score[i]]] = "Silver Medal";
            else if (i == 2) res[m[score[i]]] = "Bronze Medal";
            else res[m[score[i]]] = to_string(i + 1);
        }
        return res;
        
    }

};