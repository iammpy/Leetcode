class Solution {
    int k;
    int right;
public:
    int findKthLargest(vector<int>& nums, int k) {
        this->k=k;
        this->right=nums.size();
        int l=0,r=nums.size();

        return partion(nums,l,r);

    }
    int partion(vector<int>& nums,int l,int r){

        
        // int ran=random()%(r-l);
        int ran=(r+l)/2;
        // r=0;
        int val=nums[ran];
        int first=l;swap(nums[r-1],nums[ran]);
        
        for(int i=first;i<r;++i){
            if(nums[i]<val){
                swap(nums[i],nums[l]);
                l++;
            }
           
        }
        swap(nums[r-1],nums[l]);
        
        if(right-l==k) {
            return nums[l];
        }else if(right-l>k){
            return partion(nums, l+1, r);
        }else if(right-l<k){
            return partion(nums,first, l);
        }
        return -1;


    }
};
