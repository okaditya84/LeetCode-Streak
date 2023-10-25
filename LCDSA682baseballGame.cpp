class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for (string op : operations) {
            if (op == "C") {
                scores.pop();
            } else if (op == "D") {
                int prev = scores.top();
                scores.push(prev * 2);
            } else if (op == "+") {
                int prev1 = scores.top();
                scores.pop();
                int prev2 = scores.top();
                scores.push(prev1);
                scores.push(prev1 + prev2);
            } else {
                int score = stoi(op);
                scores.push(score);
            }
        }
        int sum = 0;
        while (!scores.empty()) {
            sum += scores.top();
            scores.pop();
        }
        return sum;
    }
};