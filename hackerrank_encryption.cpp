#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   getline(cin,s);
   s.erase(remove(s.begin(), s.end(), ' '),s.end()); 
   int b,c;
   int l = s.length();
   b = floor(sqrtf(l));
   c = ceil(sqrtf(l));
   while(b*c<l)
    b++;
    string f[b]= {""};
    int k = 0;
   for(int i=0;i<b*c;i+=c)
    {
        for(int j=i;j<i+c&&j<l;j++)
        {
            f[k] += s[j];
        }
       // cout<<f[k]<<" ";
        k++;
    }
    int j = 0;
    while(c--)
    {
        for(int i=0;i<k;i++)
         {
           if(f[i][j]>='a' && f[i][j]<='z')
           cout<<f[i][j];
         }
        cout<<" ";
        j++;
    }

    return 0;
}