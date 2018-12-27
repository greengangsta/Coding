#include<bits/stdc++.h>
using namespace std;

double dist(pair<int,int> a,pair <int,int> b)
{
	return sqrt((a.first -b.first)*(a.first -b.first) +
	(a.second -b.second)*(a.second -b.second));
}
double brut_frc(vector <int,int> ps,n)
{
	double min = DOUBLE_MAX;
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
double stripclosest(vector <pair <int,int> > strip,j,d)
{
	double min = d;
	sort(strip.begin(),strip.end();cmp2);
	for(int i=0;i<j;i++)
	  for(int k=i+1;k<j&&strip[k].second -strip[i].second<min;k++)
		  if(dist(strip[i],strip[j]<min)
			  min=dist(strip[i],strip[j]);
   return min;
}


double minimal_distance(vector<int> x, vector<int> y) {
	 vector <pair <int,int > > ps;
	for(int i=0;i<x.size();i++)
	   {
		   ps[i].first=x[i];
		   ps[i].second = y[i].
	   }
  //write your code here
	  sort(ps.begin(),ps.end(),cmp1);
	  int n = ps.size();
	  if(n<=3)
		 return brut_frc(ps,n);
	  int m =n/2;
	  pair<int,int> midpoint = ps[m];
	  float dl = minimal_distance(ps,m);
	  float dr = minimal_distance(ps+m,n-m)
	   
	   float d = min(dl,dr);
	  vector <pair <int,int > > strip(n);
	  int j=0;
	  for(int i=0;i<n;i++)
		  if(abs(ps[i].first -midpoint.first < d)
		  {
			  strip[j].first = ps[i].first;
			  strip[j].second = ps[i].second;
			  j++;
		  }
	   
  return min (d,stripclosest(strip,j,d);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
