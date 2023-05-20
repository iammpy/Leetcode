class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 完全背包问题
        // dp数组中是达到一个金额所需的最小硬币数，不行的话填INT_MAX
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        for(int i=1;i<=amount;++i){
            dp[0][i]=INT_MAX;
        }

        for(int i=1;i<=coins.size();++i){
            for(int j=1;j<=amount;++j){
                int current=j;
                int k=1;
                dp[i][j]=dp[i-1][j];
                while(j-k*coins[i-1]>=0){
                    // 更新dp，内部的min是防止过程中INT_MAX加上k之后超过int界限
                    dp[i][j]=min(dp[i][j],min(INT_MAX-k,dp[i][j-k*coins[i-1]])+k);
                    ++k;
                }
                
            }
        }

 
        return dp[coins.size()][amount]==INT_MAX?-1:dp[coins.size()][amount];

        

    }
};
