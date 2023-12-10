class Solution {
    const int M = 1e9 + 7;

    int mpow(int x, int y) {
        int res = 1;
        while (y > 0) {
            if (y & 1)
                res = (res * 1LL * x) % M;
            y >>= 1;
            x = (x * 1LL * x) % M;
        }
        return res;
    }

public:
    int numberOfGoodPartitions(vector<int> &nums) {
        int n = nums.size();
        set<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            s.insert({i, i});
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        auto combine = [&](int l, int r) {
            auto it = s.upper_bound({l, l});
            it--;
            pair<int, int> p = *it;
            vector<pair<int, int>> v;
            while (it != s.end() && it->first <= r) {
                p.second = max(p.second, it->second);
                v.push_back(*it);
                it++;
            }
            for (auto x : v) {
                s.erase(x);
            }
            s.insert(p);
        };
        for (auto x : mp) {
            if (x.second.front() < x.second.back()) {
                combine(x.second.front(), x.second.back());
            }
        }
        // Move the return statement inside the function
        return mpow(2, s.size() - 1);
    }
};
