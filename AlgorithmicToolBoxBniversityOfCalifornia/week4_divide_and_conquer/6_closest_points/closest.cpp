#include<bits/stdc++.h>
using namespace std;

double dist(pair<int,int> a,pair <int,int> b)
{
	return sqrt((a.first -b.first)*(a.first -b.first) +
	(a.second -b.second)*(a.second -b.second));
}
double brut_frc(vector <pair<int,int> >ps,int n)
{
	double min = FLT_MAX;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;++j)
			 if(dist(ps[i],ps[j])<min)
				 min = dist(ps[i],ps[j]);
	return min;
}
bool cmp1(const pair<int,int> &a,const pair<int,int > &b)
{
	return a.first < b.first;
}
bool cmp2(const pair<int,int> &a,const pair <int,int> &b)
{
	return a.second < b.second;
}
double stripclosest(vector <pair <int,int> > strip,int j,int d)
{
	double min = d;
	sort(strip.begin(),strip.end(),cmp2);
	for(int i=0;i<j;i++)
	  for(int k=i+1;k<j&&strip[k].second -strip[i].second<min;k++)
		  if(dist(strip[i],strip[j])<min)
			  min=dist(strip[i],strip[j]);
   return min;
}


double minimal_distance(vector<pair<int,int> > ps, int  l,int n) {
  //write your code here
	  sort(ps.begin(),ps.end(),cmp1);
	  if(n<=3)
		 return brut_frc(ps,n);
	  int m =n/2;
	  pair<int,int> midpoint = ps[m];
	  double dl = minimal_distance(ps,l,m);
	  double dr = minimal_distance(ps,m+1,n);
	   
	   double d = min(dl,dr);
	  vector <pair <int,int > > strip(n);
	  int j=0;
	  for(int i=0;i<n;i++)
		  if(abs(ps[i].first -midpoint.first < d))
		  {
			  strip[j].first = ps[i].first;
			  strip[j].second = ps[i].second;
			  j++;
		  }
	   
  return min (d,stripclosest(strip,j,d));
}

int main() {
  size_t n;
  std::cin >> n;
  vector<pair<int,int>> x(n);;
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i].first >> x[i].second;
  }
  for(int i=0;i<n;i++)
    cout<<x[i].first<<" "<<x[i].second<<endl;
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x,0,n) << "\n";
}
