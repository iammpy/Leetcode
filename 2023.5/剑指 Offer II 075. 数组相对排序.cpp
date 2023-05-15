// 自定义sort函数的比较函数

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int,int> hash;
        for(int i=0;i<arr2.size();i++){
            hash[arr2[i]]=i;

        } 

        auto mycomp=[&](int x,int y)->bool{
            if(hash.count(x)){
                return hash.count(y)? hash[x]<hash[y]:true;
            }else{
                return hash.count(y)? false:x<y;
            }
        };

        sort(arr1.begin(),arr1.end(),mycomp);
        return arr1;
        

    }
};
