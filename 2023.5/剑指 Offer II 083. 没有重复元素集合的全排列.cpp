class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> v;
        dfs(nums,v);

        return res;

    }
    void dfs(vector<int> nums,vector<int>& v){
        if(nums.size()==0){
            res.push_back(v);
            return ;
        }
        for(int i=0;i<nums.size();++i){
            int k=nums[i];
            swap(nums[i], nums[nums.size()-1]);
            nums.pop_back();
            v.push_back(k);
            dfs(nums,v);
            v.pop_back();
            nums.push_back(k);
            swap(nums[i], nums[nums.size()-1]);
            
        }

    }
};
