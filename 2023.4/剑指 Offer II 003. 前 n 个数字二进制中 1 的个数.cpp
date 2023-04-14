class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res=vector<int>(n+1);
        res[0]=0;
        for(int i=1;i<n+1;i++){
            if(i%2==1){
                res[i]=res[i-1]+1;
            }else if(i%2==0){
                res[i]=res[i/2];
            }
        }

        return res;

    }
};
