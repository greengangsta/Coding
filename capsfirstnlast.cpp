#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   getline(cin,s);
   stringstream ss(s);
   string t = "";
   string w;
   while(ss>>w)
   {
       if(w.length()==1)
        t += w;
       else
        {
            w[0] = toupper(w[0]);
            w[w.length()-1] = toupper(w[w.length()-1]);
            t += w;
            t += " ";
        }
   }
   cout<<t<<endl;
    return 0;
}