#include <iostream>
#include <cstdio>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("11059.in", "r", stdin);
    freopen("11059.out", "w", stdout);
#endif

    int N, s[18], tc=0;
    
    while (std::cin >> N) {
         
        tc++;

        for (int i=0; i<N; i++)
            cin >> s[i];
        
        long long max=0;    
        for (int i=0; i<N; i++) {
            long long p=s[i];
            if (p>max)
                max = p;
            for (int j=i+1; j<N; j++) {
                p *= s[j];               
                if (p>max) {
                    //cout << i << ":" << j << "=>" << p << endl;
                    max=p;
                } 
            }                
        }
        
        cout << "Case #" << tc << ": The maximum product is " << max << "." << endl << endl;        
    }

    return 0;
}