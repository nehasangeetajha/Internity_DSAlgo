#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;

    int n,m;
    cin>>n>>m;

    int arrr[n];
    for(int i=0;i<n;i++)
        cin>>arrr[i];

    int arrc[m];
    for(int i=0;i<m;i++)
        cin>>arrc[i];

    int rc = 0;
    for(int i =0;i<n;i++)
    {
        rc += min(c1*arrr[i],c2);
    }
    rc = min(rc,c3);

    int cc= 0;
    for(int i =0;i<m;i++)
    {
        cc += min(c1*arrc[i],c2);
    }
    cc = min(cc,c3);

    int ans = min(c4,rc+cc);
    cout<<"ans<<endl<<endl;
    }



}
