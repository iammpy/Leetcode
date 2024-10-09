#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


void  fun(int l,int r,vector<int>& v){
    if(l>=r) return  ;
    // 后序遍历
    fun(l,(r+l)/2,v);
    fun((r+l)/2+1,r,v);
    vector<int> temp;
    int p1=l,p2=(r+l)/2+1;
    while(p1<=(r+l)/2&&p2<=r){
        if(v[p1]<v[p2]){
            temp.push_back(v[p1]);
            p1++;
        }else{
            temp.push_back(v[p2]);
            p2++;

        }

    }
    if(p1<=(r+l)/2){
        p2=(r+l)/2;
    }else{
        p1=p2;
        p2=r;
    }
    for(int i=p1;i<=p2;i++){
        temp.push_back(v[i]);
    }

    for(int i=l;i<=r;i++){
        v[i]=temp[i-l];
    }

}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i;i<n;i++){
        cin>>v[i];
    }

    fun(0,n-1,v);
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;

}
