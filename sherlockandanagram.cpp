#include<bits/stdc++.h>
using namespace std;

int chkang(char a[], char b[]) {
  int first[26] = {0}, second[26] = {0}, c = 0;

  while (a[c] != '\0') {
    first[a[c] - 'a']++;
    c++;
  }
  c = 0;
  while (b[c] != '\0') {
    second[b[c] - 'a']++;
    c++;
  }

  for (c = 0; c < 26; c++) {
    if (first[c] != second[c])
      return 0;
  }

  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    char s[100];
    char sub1[100] = {0};
    char sub2[100] = {0};
    scanf("%s", s);

    int count = 0;
    for (int l= 1; l< strlen(s); l++) {
      memset(sub1, 0, l);
      for (int i = 0; i < strlen(s) - l; i++) {
        strncpy(sub1, &s[i], l);
        memset(sub2, 0, l);
        for (int j = i + 1; j < strlen(s) - l + 1; j++) {
          strncpy(sub2, &s[j], l);
          if (chkang(sub1, sub2) == 1) {
            count++;
          }
        }
      }
    }

    printf("%d\n", count);
  }

  return 0;
}