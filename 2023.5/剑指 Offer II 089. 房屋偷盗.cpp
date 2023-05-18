class Solution {
public:
    int rob(vector<int>& nums) {
        // dp数组中存储如果选取当前房子那从这里到终点的最多金额
        vector<int> dp(nums.size()+3,0);
        int n=nums.size();
        dp[n+2]=0;
        dp[n+1]=0;
        dp[n]=0;
        for(int i=n-1;i>-1;--i){
            dp[i]=nums[i]+max(dp[i+2],dp[i+3]);

        }
        return max(dp[0],dp[1]);


    }
};
