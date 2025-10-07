//https://leetcode.com/problems/longest-palindromic-substring/description/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true));

        int start = 0;
        int max = 1;

        for(int i = n - 2; i >= 0; --i ){
            for(int j = i + 1; j < n; ++j){
                dp[i][j] = false;

                if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];

                    if(dp[i][j] && max < j - i + 1){
                        max = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, max);
    }
};
