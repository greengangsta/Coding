#include<bits/stdc++.h>
using namespace std;

bool cmp1(const pair<int,int> &a,const pair<int,int > &b)
{
    return a.first <= b.first;
}
bool cmp2(const pair<int,int> &a,const pair <int,int> &b)
{
	return a.second <= b.second;
}
double min(double x,double y)
{
    return (x<y)?x:y;
}
double dist(const pair<int,int> &a,const pair <int,int> &b)
{
    cout<<"check dist"<<endl;
	return sqrt(
	             (a.first -b.first)*(a.first -b.first) +
     	         (a.second -b.second)*(a.second -b.second)
            	);
}
double brut_frc(vector <pair<int,int> >ps)
{
    cout<<"check brut_frc"<<endl;
	double min = 100000.000000;
	for(int i=0;i<ps.size();i++)
		for(int j=i+1;j<ps.size();j++)
			 if(dist(ps[i],ps[j])<min)
				 min = dist(ps[i],ps[j]);
   cout<<"min ="<<min<<endl;
	return min;
}

double stripclosest(vector <pair <int,int> > strip,int j,int d)
{
    cout<<"check stripclosest"<<endl;
	double min = d;
	for(int i=0;i<j;++i)
	  for(int k=i+1;k<j && (strip[k].second -strip[i].second)<min;++k)
		  if(dist(strip[i],strip[k])<min)
			  min=dist(strip[i],strip[k]);
			  cout<<"min from strip closest is : "<<min<<endl;
   return min;
}


double minimal_distance(vector<pair<int,int>> px, vector <pair<int ,int>> py) {
  //write your code here
  cout<<"check minimal_distance"<<endl;
  int  n = px.size();
	  if(n<=3)
		 return brut_frc(px);
	   int m = n/2;
	  cout<<"mid point of partition is : "<<m<<endl;
	  pair<int,int> midpoint = px[m];
	  cout<<"mid point co-ordinates are : "<<midpoint.first<<" "<<midpoint.second<<endl;
	  vector <pair<int,int>> qx(m+1),qy(m+1);
	  vector <pair<int,int>> rx(n-m-1),ry(n-m-1);
	  int j=0,k=0;
	    for(int i=0;i<py.size();i++)
	      {
	          if(py[i].first<=midpoint.first)
	             qy[j++]=py[i];
	          else
	             ry[k++]=py[i];
	      }
	      j=0;
	    for(int i=0;i<=m;i++)
	         qx[i] = px[i];
	    for(int i=m+1;i<n;i++)
	         rx[j++] =px[i];
	  double dl = minimal_distance(qx,qy);
	  double dr = minimal_distance(rx,ry);
	   cout<<"left min is = "<<dl<<endl;
	   cout<<"right min is = "<<dr<<endl;
	   double d = min(dl,dr);
	   cout<<"d : "<<d<<endl;
	  vector <pair <int,int > > strip(n);
	   j=0; 
	  for(int i=0;i<n;i++)
		  if(abs(py[i].first-midpoint.first) <= d)
		  {
			  strip[j].first = py[i].first;
			  strip[j].second = py[i].second;
			  j++;
			  cout<<"strip recently added is : "<<py[i].first<<" "<<py[i].second<<endl;
		  }
	   
  return min (d,stripclosest(strip,j,d));
}

int main() {
  size_t n;
  std::cin >> n;
  vector<pair<int,int>> px(n),py(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> px[i].first >> px[i].second;
    py[i].first = px[i].first;
    py[i].second = px[i].second;
    
  }

  std::cout << std::fixed;
  	  sort(px.begin(),px.end(),cmp1);
  	  sort(py.begin(),py.end(),cmp2);
  	      for(int i=0;i<n;i++)
    cout<<py[i].first<<" "<<py[i].second<<endl;
  std::cout << std::setprecision(9) << minimal_distance(px,py) << "\n";
}
