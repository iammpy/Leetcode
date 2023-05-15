class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // bool b=0;
        if(nums.size()<2) return nums[0];
        int l=0,r=nums.size();
        int mid;
        while(l<r){
            mid=(l+r)/2;
            if(mid%2==1) --mid;
            if(nums[mid]!=nums[mid+1]) {
                if(mid==0||nums[mid]!=nums[mid-1]) return nums[mid];
                else{
                    r=mid-1;
                }
            }else{
                l=mid+2;
            }
        }
        return -1;

    }
};
