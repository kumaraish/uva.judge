#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n, m;
    while (1) {
        cin >> n;
        if (n==0) break;
        cin >> m;
        
    	char b[101][101];

    	for (int i=1; i<=n; i++) {
    		for (int j=1; j<=m; j++) {
    			cin >> b[i][j];
    		}
    	}

        int count=0, pcount=0;
    	for (int i=1; i<=n; i++) {
    		for (int j=1; j<=m; j++) {
                int pmm=m;                
                for (int ii=i; ii<=n; ii++) {
                    if (b[ii][j] == '0') break;
                    int mm=0;
                    int jj=j;
                    for (; jj<=pmm; jj++) {
                        if (b[ii][jj] == '1') {                            
                            mm++;
                        }
                        else break;                   
                    }
                    pmm = jj-1;
                    count += mm;                    
                }
                pcount = count;
    		}
    	}
        
        cout << count << endl;
    }

    return 0;
}