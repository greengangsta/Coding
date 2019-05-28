#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  int count = 1;
  int i = 0;
  int min = a[0];
  while (a[i] <= min + 4 && i < n - 1) {
    i++;
    if (a[i] > min + 4) {
      min = a[i];
      count++;
    }
  }
  cout << count << endl;

  return 0;
}