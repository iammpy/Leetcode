class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int res=-1;
        vector<int> pre(nums.size()+1);
        pre[0]=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            pre[i+1]=sum;
        }


        // int half=sum/2;
        for(int i=0;i<nums.size();i++){
            if(sum-nums[i]==pre[i]*2) return i;
        }




        return res;


    }
};
