#include <iostream>

using namespace std;
int n,m,k,cnt;
int arr[1005];
int st[1005],pt1,pt2;

int main2(){
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        cnt=1;
        pt1=0,pt2=1;
        for(int j=1;j<=n;j++){
            cin>>arr[j];
        }
        while(cnt!=n+1){
            if(pt1!=0&&st[pt1]==cnt){
                pt1--;
                cnt++;
                continue;
            }
            else if(pt2!=n+1){
                if(arr[pt2]==cnt){
                    pt2++;
                    cnt++;
                    continue;
                }
                else {
                    pt1++;
                    if(pt1>m)break;
                    st[pt1]=arr[pt2];
                    pt2++;
                    continue;
                }
            }
            else break;
        }
        if(cnt!=n+1){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
}