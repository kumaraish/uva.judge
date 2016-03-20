#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("10662.in", "r", stdin);
#endif

    int T, R, H;

    while (std::cin >> T >> R >> H) {
        int pT[20], pR[20], pH[20];
        int sT, sR, sH;
        int _TR[20][20], _RH[20][20], _HT[20][20];

        for (int i=0; i<T; i++) {
            cin >> pT[i];
            for (int j=0; j<R; j++) {
                cin >> _TR[i][j];
            }
        }
        
        for (int i=0; i<R; i++) {
            cin >> pR[i];
            for (int j=0; j<H; j++) {
                cin >> _RH[i][j];
            }
        }
        
        for (int i=0; i<H; i++) {
            cin >> pH[i];
            for (int j=0; j<T; j++) {
                cin >> _HT[i][j];
            }
        }
        
        int minS=2147483647, sum;
        for (int i=0; i<T; i++)
            for (int j=0; j<R; j++)
                for (int k=0; k<H; k++)
                    if (_TR[i][j] == 0 && _RH[j][k] == 0 && _HT[k][i] == 0) {
                        sum = pT[i] + pR[j] + pH[k];                                               
                        if (sum < minS) {
                            sT = i; sR = j; sH = k; 
                            minS = sum;  
                        } 
                    }       
                                
        if (minS == 2147483647)
            cout << "Don't get married!" << endl;
        else cout << sT << " " << sR << " " << sH << ":" << minS << endl;
    }

    return 0;
}

