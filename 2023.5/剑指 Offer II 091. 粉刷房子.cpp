class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // 记录每一个房子分别使用三种颜色的总花费
        vector<vector<int>> dp(costs.size()+1,vector<int>(3,0));
        int n=costs.size();
        dp[n][0]=0;
        dp[n][1]=0;
        dp[n][2]=0;
        for(int i=n-1;i>-1;--i){
            dp[i][0]=costs[i][0]+min(dp[i+1][1],dp[i+1][2]);
            dp[i][1]=costs[i][1]+min(dp[i+1][0],dp[i+1][2]);
            dp[i][2]=costs[i][2]+min(dp[i+1][1],dp[i+1][0]);
        }
        int res=min(dp[0][0],dp[0][1]);
        res=min(res,dp[0][2]);
        return res;



    }
};
