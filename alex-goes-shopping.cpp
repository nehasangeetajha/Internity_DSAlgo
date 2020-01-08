#include<iostream>
using namespace std;

bool shop(int a,int k,int arr[],int n)
{
    for(int i =0;i<n;i++)
    {
        if(a == arr[i])
            return true;
        for(int j =1;j<k;j++)
        {
            if(a==j*arr[i])
                return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
     int q;
     cin>>q;
     int A[q],k[q];
     for(int i =0;i<q;i++)
     {
         cin>>A[i]>>k[i];
     }

     for(int i =0;i<q;i++)
     {
         if(shop(A[i],k[i],arr,n))
         {
             cout<<"YES"<<endl;
         }
         else
            cout<<"NO"<<endl;
     }

}
