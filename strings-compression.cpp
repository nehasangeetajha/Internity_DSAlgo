#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int arr[26]={0};

    for(int i =0;i<s.size();i++)
    {
        int index = s[i]-'a';
        arr[index]++;
        if(s[i]!=s[i+1])
        {
            if(arr[index]!=1)
            {
                cout<<s[i]<<arr[index];
            }
            else
                cout<<s[i];
        }
    }


}
