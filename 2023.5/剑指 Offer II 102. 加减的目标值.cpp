class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // hash表存储考虑前n个数时不同target对应的数量
        vector<unordered_map<int,int>> dp(nums.size()+1,unordered_map<int,int>());
        // dp[i][target]=dp[i-1][target+1]+dp[i-1][targer-1];
        //使用hash只存储那些有值的target
        dp[0][0]=1;
        for(int i=1;i<=nums.size();++i){
            int num=nums[i-1];
            for(auto it:dp[i-1]){
                if(dp[i].count(it.first+num)){
                    dp[i][it.first+num]+=it.second;
                }else{
                    dp[i][it.first+num]=it.second;
                }
                 if(dp[i].count(it.first-num)){
                    dp[i][it.first-num]+=it.second;
                }else{
                    dp[i][it.first-num]=it.second;
                }
            }

        }

        return dp[nums.size()].count(target)?dp[nums.size()][target]:0;


    }
};
