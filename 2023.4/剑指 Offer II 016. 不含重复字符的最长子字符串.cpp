class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;

        //滑动窗口

        int l=0,r=0;
        unordered_map<char,int> have;
        while(r<s.size()){
            char c=s[r];
            r++;
            if(!have.count(c)){
                have.insert(make_pair(c,r-1));
                res=max(res,r-l);
            }else{
                for(int i=l;i<have[c];i++){
                    have.erase(s[i]);
                }
                l=have[c]+1;
                have[c]=r-1;
            }
        }


        return res;

    }
};
