#include<bits/stdc++.h>
using namespace std;

int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int d;
        cin>>d;
        cin>>s;
        int count=0,l=s.length();
        for(int i=0;i<l;i++)
        {
          if(s[i]=='P')
           {
               count++;
           }
        }
        int count1=count;
        float p;
        p = (float)count/(float)l;
        if(p>=0.75)
         cout<<0<<endl;
         
        else
        {
                for(int i=2;i<l-2;i++)
                 {
                     if(s[i]=='A')
                     {
                      if((s[i-1]=='P'||s[i-2]=='P')&&(s[i+1]=='P'||s[i+2]=='P'))
                       {
                         count++;
                         p = (float)count/float(l);
                         if(p>=0.75)
                          break;
                       }
                     }
                 }
           if(p>=0.75)
            cout<<count-count1<<endl;
           else
            cout<<-1<<endl;
        }
    }
    
    
    return 0;
}
