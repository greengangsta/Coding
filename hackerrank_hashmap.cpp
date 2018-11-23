#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, flag = 0;
  cin >> m >> n;

  unordered_map<string, int> mp1;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    int p = 1;
    if (mp1.find(s) == mp1.end())
      mp1.insert(make_pair(s, p));
    else {
      auto it = mp1.find(s);
      it->second += 1;
    }
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (mp1.find(s) == mp1.end() || (mp1.find(s)->second == 0)) {
      cout << "No";
      flag = 1;
      break;
    } else {
      auto it = mp1.find(s);
      it->second -= 1;
    }
  }
  if (flag == 0)
    cout << "Yes";
  return 0;
}