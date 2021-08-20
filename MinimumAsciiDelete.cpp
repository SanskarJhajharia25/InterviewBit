/*
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.
*/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size(), sum1 = 0, sum2 = 0;
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));

        sum1 = accumulate(s1.begin(), s1.end(), 0);
        sum2 = accumulate(s2.begin(), s2.end(), 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int ans = dp[n][m];
        return sum1 + sum2 - 2 * ans;
    }
};
