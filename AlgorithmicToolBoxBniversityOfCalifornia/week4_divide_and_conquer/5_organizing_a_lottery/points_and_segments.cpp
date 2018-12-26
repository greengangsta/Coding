#include<bits/stdc++.h>
using namespace std;

using std::vector;

bool cmp(const pair<int,char> &a,const pair<int,char> &b)
{
    if(a.first == b.first)
      return (a.second < b.second);
    else
     return (a.first < b.first); 
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  unordered_map<int,int > mp;
  for(int i=0;i<points.size();i++)
    mp.insert(make_pair(points[i],0));
  int p,s,j=0;
  p = points.size();
  s = starts.size();
   vector <pair <int ,char> > pr;
   for(int i=0;i<p;i++)
     pr.push_back(make_pair(points[i],'p'));
   for(int i=0;i<s;i++)
     pr.push_back(make_pair(starts[i],'l'));
   for(int i=0;i<s;i++)
     pr.push_back(make_pair(ends[i],'r')); 
   sort(pr.begin(),pr.end(),cmp); 
 // for(auto it = pr.begin();it!=pr.end();it++)
  //   cout<<it->first<<" "<<it->second<<"  ";
  //   cout<<endl;
    int ls=0,le=0;
   for(auto it=pr.begin();it!=pr.end();it++)
    {
        if(it->second=='l')
         ls++;
        else if(it->second=='r')
         le++;
        else if(it->second=='p')
        {
         auto x = mp.find(it->first);
          x->second = ls-le;
        }
    }
    for(int i=0;i<points.size();i++)
      {
          auto it = mp.find(points[i]);
          cnt[i] = it->second;
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
