#include<bits/stdc++.h>
using namespace std;

using std::vector;

int bin_src_count(vector <int> a,int p)
{
	int n=a.size();
	int l=0,r=n-1;
	int m;
	while(l<=r){
	int m = l + (r-l)/2;
	if(a[m]<=p)
		l=m+1;
	else
		r= m-1;
	}
	
	return l;
}
int bin_src_count1(vector <int> a,int p)
{
	int n=a.size();
	int l=0,r=n-1;
	int m;
	while(l<=r){
	int m = l + (r-l)/2;
	if(a[m]<=p)
		l=m+1;
	else
		r= m-1;
	}
	
	return n-l;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  int n=starts.size();
  sort(starts.begin(),starts.end());
  sort(ends.begin(),ends.end());
  for(int i=0;i<points.size();i++)
   {
	   int s,e;
	  s = bin_src_count(starts,points[i]);
	  e = bin_src_count1(ends,points[i]);
	//  cout<<s<<" s and e "<<e<<endl;
	  cnt[i]= s+e-n;
   }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector <int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }

}
