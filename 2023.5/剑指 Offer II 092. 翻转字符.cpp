class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // 从后向前，记录当前需要翻转多少次，并且记录当前的0的个数和1的个数
        // int zeronum=0;
        // int turn0=0;
        // int turn1=0;
        // char pre='1';
        // // int need=0;
        // for(int i=s.size();i>-1;--i){
        //     char c=s[i];
        //     if(c=='0'){
        //         if(pre=='0'){
                    
        //         }else if(pre=='1'){

        //         }

        //         zeronum++;
        //         pre='0';

        //     }else if(c=='1'){
        //          if(pre=='0'){
                    
                    
        //         }else if(pre=='1'){
        //             // turn1=zeronum;

        //         }
        //         turn1=zeronum;
        //         pre='1';

        //     }
        // }

        // 由于要求单调，最终字符串必然是0后面跟着全是1，可以讨论1从不同的位置开始时需要翻转的字符数，先使用一个数组存储后面0的个税
        // 同时用一个数组存储前面1的个数
        vector<int> pre1(s.size()+1,0);
        vector<int> back0(s.size()+1,0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                pre1[i+1]=pre1[i]+1;
            }else{
                pre1[i+1]=pre1[i];
            }
        }
        for(int i=s.size()-1;i>-1;--i){
            if(s[i]=='1'){
                back0[i]=back0[i+1];
            }else{
                back0[i]=back0[i+1]+1;
            }
        }
        int pos=s.find("01");
        int res=INT_MAX;
        while(pos<s.size()){

            res=min(res,pre1[pos]+back0[pos+1]);
            pos=s.find("01",pos+1);
        }
        res=min(res,pre1[s.size()]);
        res=min(res,back0[0]);


        return res;



    }
};
