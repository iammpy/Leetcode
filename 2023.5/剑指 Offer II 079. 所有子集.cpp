class Solution {
    vector<vector<int>> res;
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        res.push_back({});
        add(v,nums,0);


        return res;

    }
    void add(vector<int>& v,vector<int>& nums,int l){
        if(l<nums.size()){
            // res.push_back(v);
            add(v,nums,l+1);
            
            v.push_back(nums[l]);
            res.push_back(v);
            add(v,nums,l+1);
            v.pop_back();

        }
    }
};
