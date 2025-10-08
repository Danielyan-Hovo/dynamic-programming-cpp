//https://leetcode.com/problems/generate-parentheses/description/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        function<void(int, int, string)> backtrack = [&](int open, int close, string current) {
            if(open > n || close > n || open < close) {
                return;
            }
            if(open == n && close == n) {
                result.push_back(current);
                return;
            } 

            backtrack(open + 1, close, current + "(");
            backtrack(open, close + 1, current + ")");
        };

        backtrack(0, 0, "");
        return result;
    }
};
