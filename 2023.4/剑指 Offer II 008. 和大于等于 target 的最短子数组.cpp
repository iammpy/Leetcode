class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX;
        int l=0,r=0;
        while(r<nums.size()){
            r++;
            int s=sum(nums,l,r);

            while(s>=target){
                res=min(r-l,res);
                s=s-nums[l];
                l++;
            }
            
        }
        if(res==INT_MAX) res=0;


        return res;
    }

    int sum(vector<int>& nums ,int l,int r){
        int res=0;
        for(int i=l;i<r;i++){
            res+=nums[i];
        }
        return res;
    }
};
