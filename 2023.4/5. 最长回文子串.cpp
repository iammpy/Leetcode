//双指针从里向外扩散，因为对于最长子串的问题不能在开始确定边界

class Solution {
string palindrome(string s,int l,int r){
    while(l>=0&&r<s.size()&&s[l]==s[r]){
        l--;
        r++;
    }
    return s.substr(l+1,r-l-1);
}

public:
    string longestPalindrome(string s) {
        string res;
            for(int i=0;i<s.size();i++){
                string s1=palindrome(s, i, i);
                string s2=palindrome(s, i, i+1);
                res=res.size()>s1.size() ? res:s1;
                res=res.size()>s2.size()?res:s2;


            }
        return res;

    }
};
