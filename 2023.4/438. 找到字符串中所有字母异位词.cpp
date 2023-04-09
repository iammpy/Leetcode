//在最小覆盖串中因为初态必然不可能是valid的，所以判断条件放在了更新之后
//但是在这一题中初态就是可能的解，所以需要在开头就判断一下，这就导致了最后一下更新之后如果后续状态还是valid的情况却不能进循环了，导致少了最后一个解
//所以需要进循环之前额外判断一下，或者出循环之后判断一下

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l=0,r=0;
        unordered_map<char, int> window,need;
        for(char c:p) need[c]++;
        r=l+p.size();
        int valid=0;
        for(int i=0 ;i<r;i++){
            if(need.count(s[i])){
                window[s[i]]++;
                if(window[s[i]]==need[s[i]]) valid++;
            }

        }
        vector<int> res;
 

        //左右指针同步滑动
        while(r<s.size()){
            if(valid==need.size()){
                res.push_back(l);
            }
            char lc=s[l];
            char rc=s[r];
            if(lc!=rc) {
                if(need.count(lc)){
                    
                    if(window[lc]==need[lc]) valid--;
                    window[lc]--;
                }
                if(need.count(rc)){
                    window[rc]++;
                    if(window[rc]==need[rc]) valid++;
                    
                }

            }
            l++;
            r++;


        }
         if(valid==need.size()){
                res.push_back(l);
            }
    return res;

    }
};
