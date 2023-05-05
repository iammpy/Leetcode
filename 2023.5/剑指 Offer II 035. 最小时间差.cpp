class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res=INT_MAX;
        vector<int> v;
        int day=24*60;
        for(string str:timePoints){
            v.push_back(trans(str));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;++i){
            int cur=v[i+1]-v[i];
            res=min(res,min(cur,day-cur));

        }
        int cur=v[v.size()-1]-v[0];
        res=min(res,min(cur,day-cur));
        return res;
    }
    int trans(string s){
        // int res;
        int pos=s.find(':');
        int hour=stoi(s.substr(0,2));
        int min=stoi(s.substr(pos+1,2));


        return hour*60+min;
    }
};
