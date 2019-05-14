#include<bits/stdc++.h>
using namespace std;

int main()
{

   int n;
   cin>>n;
   int a[26]={0};
   for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
       for(int j=0;j<s.length();j++)
        {
            if(a[s[j]-'a']==i)
             a[s[j]-'a']+=1;
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
      if (a[i] == n)
        count++;
    }
    cout << count << endl;

    return 0;
}