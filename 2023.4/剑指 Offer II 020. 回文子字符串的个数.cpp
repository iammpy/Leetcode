class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        for(int i=0;i<s.size();++i){
            res+=count1(s,i);
            res+=count2(s,i,i+1);
        }

        return res;


    }
    int count1(string s ,int mid){
        int res=1;
        int l=mid-1,r=mid+1;
        while(l>-1&&r<s.size()){
            if(s[l]==s[r]){
                res++;
                l--;
                r++;
            } else break;

        }

        return res;
    }

    int count2(string s,int l,int r){
        int res=0;
        while(l>-1&&r<s.size()){
            if(s[l]==s[r]){
                res++;
                l--;
                r++;
            } else break;

        }


        return res;
    }
};
