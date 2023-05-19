class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        // vector<vector<int>> dp()
        int res=-1;
        unordered_map<int,int> hash;
        for(int i=0;i<arr.size();++i){
            hash[arr[i]]=i;
        }
        for(int i=arr.size()-1;i>0;--i){
            
            for(int j=i;j>-1;--j){
                int len=2;
                int back=arr[i],pre=arr[j];
                int cha=arr[i]-arr[j];
                while(hash.count(cha)&&cha<pre){
                    back=pre;
                    pre=cha;
                    cha=back-pre;
                    len++;
                }


                res=max(len,res);

            }

        }
        if(res>2) return res;
        else return 0;

    }
};
