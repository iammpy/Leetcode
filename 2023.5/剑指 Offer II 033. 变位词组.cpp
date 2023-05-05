class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { 
        vector<vector<string>> res;
        unordered_map<string,int> hash;
        // 排序之后的字符串作为变为词组的唯一标识
        for(string str:strs){
            string s=str;
            sort(s.begin(),s.end());
            if(hash.find(s)!=hash.end()){
                res[hash[s]].push_back(str);
            }else{
                // not found
                hash.insert(make_pair(s,res.size()));
                res.push_back({});
                res[res.size()-1].push_back(str);
            }
            
        }


        return res;


    }
};
