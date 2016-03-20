#include <iostream>
#include <cstdio>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("10908.in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {        
        int M, N, Q;
        cin >> M >> N >> Q;

        char block[101][101];
        for (int i=0; i<M; i++) 
            for (int j=0; j<N; j++)           
                cin >> block[i][j];
        
        cout << M << " " << N << " " << Q << endl;
        int r, c;
        for (int i=1; i<=Q; i++) {
            cin >> r >> c;            
                       
            int incr=0, radius=0;            
            while (1) {
                incr++;
                int ltx=r-incr;
                int lty=c-incr;
                int rtx=r-incr;
                int rty=c+incr;
                int lbx=r+incr;
                int lby=c-incr;
                int rbx=r+incr;
                int rby=c+incr;
                
                if (ltx<0 || lty<0 || rtx<0 || rty>=N) break;
                if (lbx>=M || lby<0 || rbx>=M || rby>=N) break;
                
                bool next=true; 
                
                //cout << ltx << ":" << lty << " : " << rtx << ":" << rty << " : " 
                //     << lby << ":" << lby << " : " << rbx << ":" << rby << "=>" ;
                                                                               
                for (int i=lty+1; i<=rty && next; i++)
                    if (block[ltx][i] != block[ltx][i-1]) next=false;
                    
                for (int i=lby+1; i<=rby && next; i++)
                    if (block[lbx][i] != block[lbx][i-1]) next=false;
                    
                for (int i=ltx+1; i<=lbx && next; i++)
                    if (block[i][lty] != block[i-1][lty]) next=false;
                    
                for (int i=rtx+1; i<=rbx && next; i++)
                    if (block[i][rty] != block[i-1][rty]) next=false;   
                    
                for (int i=ltx; i<=lbx; i++)
                    for (int j=lty; j<=rty; j++)
                        if (block[i][j] != block[r][c])
                            next = false;                       
                    
                //cout << next << " : r" << incr << endl;                                                 
                    
                if (next) {
                    /*for (int i=ltx; i<=lbx; i++) {
                        for (int j=lty; j<=rty; j++)
                            cout << block[i][j];
                        cout << endl;
                    }*/
                    
                    radius = incr;
                }                         
            }
                       
            cout << 2*radius+1 << endl;            
        }             
    }

    return 0;
}