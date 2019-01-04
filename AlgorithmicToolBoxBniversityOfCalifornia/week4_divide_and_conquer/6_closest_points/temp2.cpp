#include<bits/stdc++.h>
using namespace std;

bool cmp1(const pair<int,int> &a,const pair<int,int > &b) // to sort according to x co-ordinate
{
    return a.first < b.first;
}
bool cmp2(const pair<int,int> &a,const pair <int,int> &b) //to sort according to y co-ordinate
{
	return a.second < b.second;
}
float minm(float x,float y)  //minimum of two float values
{
    return (x<y)?x:y;
}
float dist(const pair<int,int> &a,const pair <int,int> &b) // to calculate distance
{
   // cout<<"check dist"<<endl;
	return sqrt(
	             (a.first -b.first)*(a.first -b.first) +
     	         (a.second -b.second)*(a.second -b.second)
            	);
}
float brut_frc(vector <pair<int,int> >ps)   // to find the distance with bruteforce for less than 4 points.
{
  //  cout<<"check brut_frc"<<endl;
	float min = dist(ps[0],ps[1]);
	for(int i=0;i<ps.size();i++)
		for(int j=i+1;j<ps.size();j++)
			 if(dist(ps[i],ps[j])<min)
				 min = dist(ps[i],ps[j]);
  //cout<<"min brut frc is  ="<<min<<endl;
	return min;
}

float stripclosest(vector <pair <int,int> > strip,int j,float d) // to calculate if there is a pair with minmum distance within the strip
{
   // cout<<"check stripclosest1"<<endl;;
   //  cout<<"check stripclosest2"<<endl;
	float min = d;
	for(int i=0;i<j;++i)
	  for(int k=i+1;k<j && (strip[k].second-strip[i].second)<min;++k)
		  if(dist(strip[i],strip[k])<min)
			  min=dist(strip[i],strip[k]);
		//	  cout<<"min from strip closest is : "<<min<<endl;
   return min;
}


float minimal_distance(vector<pair<int,int>> px, vector <pair<int ,int>> py)  // to find the pair of points with minimum distance.
 {
   //  for(int i=0;i<px.size();i++)
   // cout<<px[i].first<<" "<<px[i].second<<"    "<<py[i].first<<" "<<py[i].second<<endl;
  //write your code here
 // cout<<"check minimal_distance"<<endl;
  int  n = px.size();
	  if(n<=3)
		 return brut_frc(px);
	   int m = n/2;
	//  cout<<"mid point of partition is : "<<m<<endl;
	  pair<int,int> midpoint = px[m-1];
	//  cout<<"mid point co-ordinates are : "<<midpoint.first<<" "<<midpoint.second<<endl;
	  vector <pair<int,int>> qx(m),qy(m);
	  vector <pair<int,int>> rx(n-m),ry(n-m);
	  int j=0,k=0;
	     for(int i=0;i<m;i++)
	         qx[i] = px[i];
	    for(int i=m;i<n;i++)
	         rx[j++] =px[i];
	         j=0,k=0;
	    for(int i=0;i<py.size();i++)
	      {
	          if(py[i].first<=midpoint.first)
	             qy[j++]=py[i];
	          else
	             ry[k++]=py[i];
	      }
//	      cout<<"sizes are "<<qx.size()<<" "<<qy.size()<<" "<<rx.size()<<" "<<ry.size()<<endl;
	      j=0;
	  float dl = minimal_distance(qx,qy);
	  float dr = minimal_distance(rx,ry);
//	  cout<<"left min is = "<<dl<<endl;
//	  cout<<"right min is = "<<dr<<endl;
	   float d = minm(dl,dr);
//	   cout<<"d : "<<d<<endl;
	  vector <pair <int,int > > strip(n);
	   j=0; 
	  for(int i=0;i<py.size();i++)
		  if(abs(py[i].first-midpoint.first) < d)
		  {
			  strip[j].first = py[i].first;
			  strip[j].second = py[i].second;
			  j++;
//			  cout<<"strip recently added is : "<<py[i].first<<" "<<py[i].second<<endl;
		  }
//	   cout<<"value of final j is : "<<j<<endl;
  return minm(d,stripclosest(strip,j,d));
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
  	      
  	
  std::cout << std::setprecision(9) << minimal_distance(px,py) << "\n";
}
