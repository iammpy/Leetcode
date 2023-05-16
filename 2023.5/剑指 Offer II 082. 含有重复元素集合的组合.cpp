class Solution {
    vector<vector<int>> res;
    int pre=-1;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        dfs(candidates,target,0,v,0,true);
        return res;


    }
    

    void dfs(vector<int>& candidates, int target,int id,vector<int>& v,int sum,bool select){
        if(id>=candidates.size()) return;
        dfs(candidates,target,id+1,v,sum,false);
        // 如果一个数字前面没有选择，那后面就不能再选了
        bool canSelect=true;
        if(id>0&&candidates[id-1]==candidates[id]&&!select) canSelect=false;
        if(canSelect){
            if(sum+candidates[id]==target){
                v.push_back(candidates[id]);
                res.push_back(v);
                v.pop_back();
                
                return;
                
            }else if(sum+candidates[id]<target){
                
                v.push_back(candidates[id]);
                dfs(candidates,target,id+1,v,sum+candidates[id],true);
                v.pop_back();
            }
        }



    }
};
