class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int l=0;
        int r=0;
        set<int> myset;
        while(r<nums.size()){
            int num=nums[r];
            r++;
            auto it=myset.lower_bound(max(num,INT_MIN+t)- t);
            if(it!=myset.end()&&*it<=min(num,INT_MAX-t)+t){
                return true;
            }
            

            myset.insert(num);
            if(r-l>k){
                
                myset.erase(nums[l]);

                l++;
            }
        }
        return false;

    }
};
