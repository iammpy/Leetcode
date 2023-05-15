class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=min(x+1,INT_MAX);
        long long mid;
        while(l<r){
            mid=(l+r)/2;
            if(mid*mid<=x){
                if(pow(mid+1, 2)>x) return mid;
                else{
                    l=mid+1;
                }

            }else{
                r=mid;
            }

        }
        return l;


    }
};
