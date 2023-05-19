class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size(),n=t.size();
        if(m<n) return 0;
        vector<vector<long long>> dp(s.size()+1,vector<long long>(t.size()+1,0));
        for(int i=0;i<=m;++i){
            dp[i][0]=1;
        }

        for(int i=1;i<=m;++i){
            for(int j=(i-1+n-m>1?i+n-1-m:1);j<=n;++j){
                
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[m][n];

    }
};
