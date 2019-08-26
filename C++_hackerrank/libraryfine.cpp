#include <bits/stdc++.h>

using namespace std;

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    // Complete this function
    int fine;
    if(y1<y2)
        return 0;
    else if(y1==y2)
    {
        if(m1<m2)
            return 0;
        else if(m1==m2)
        {
            if(d1<=d2)
                return 0;  
            else
            {
                fine=(abs(d2-d1))*15;
            return fine;
            }
        }
        else
        {
            fine=(abs(m2-m1))*500;
            return fine;
        }
    }
    else
        return 10000;
}

int main() {
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    int d2;
    int m2;
    int y2;
    cin >> d2 >> m2 >> y2;
    int result = libraryFine(d1, m1, y1, d2, m2, y2);
    cout << result << endl;
    return 0;
}
