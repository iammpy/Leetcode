//快慢指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast=0,slow=0;
        for(auto i:nums){
            if(nums[fast]==val){
                fast++;
            }else{
                nums[slow]=nums[fast];
                slow++;
                fast++;
            }
        }

        return slow;

    }
};
