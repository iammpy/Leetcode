//0不需要存储，实际上就是把非0元素移到前面

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast=0;
        int slow=0;

        for(auto i:nums){
            if(nums[fast]==0){
                fast++;
            }else{
                nums[slow]=nums[fast];
                slow++;
                fast++;
            }

        }
        while(slow<nums.size()){
            nums[slow]=0;
            slow++;
        }


    }
};
