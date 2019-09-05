#include<bits/stdc++.h>
using namespace std;

int main()
{
   double nums[10] = {1.0, 2.0, 3.0, 4.0, 5.0,
                                   6.0, 7.0, 8.0, 9.0, 10.0};
    int ws = 4;
    double mavg = nums[0]+nums[1]+nums[2] + nums[3];
    mavg /= 4;
    cout<<mavg<<endl;
    for(int i = 4;i<10;i++)
     {
         mavg += nums[i]/4;
         mavg -= nums[i-4]/4;
         cout<<mavg<<endl;
     }





    return 0;
}
