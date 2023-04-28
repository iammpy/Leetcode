

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> store(32,0);
        for(auto j:nums){
            int k=0;
            for(int i=0;i<32;i++){
                store[k]+=j&1;
                j=j>>1;
                k++;
            }
        }
        int res=0;
        for(int i=31;i>-1;i--){
            res=res<<1;
            res=res|store[i]%3;
            
        }
        return res;

    }
};
