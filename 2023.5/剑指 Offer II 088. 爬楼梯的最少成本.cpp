class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> sumcost(cost.size(),0);
        sumcost[cost.size()-1]=cost[cost.size()-1];
        sumcost[cost.size()-2]=cost[cost.size()-2];
        for(int i=cost.size()-3;i>=0;--i){
            sumcost[i]=min(cost[i]+sumcost[i+1],cost[i]+sumcost[i+2]);
        }
        return min(sumcost[0],sumcost[1]);

    }
};
