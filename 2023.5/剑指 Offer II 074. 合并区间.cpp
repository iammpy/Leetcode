
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        for(auto inter:intervals){
            if(res.size()==0) res.push_back(inter);
            else{
                auto ba=res.back();
                if(inter[0]>ba[1]) res.push_back(inter);
                else if(inter[0]<=ba[1]){
                        if(inter[1]>ba[1]){
                        res.back()[1]=inter[1];
                        }
                }

            }
        }
        return res;
        

    }
};
