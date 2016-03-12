#include <iostream>

int main() {

	#ifndef ONLINE_JUDGE
    freopen("102.in", "r", stdin);
    //freopen("res.out", "w", stdout);
	#endif
   
   	int B[11];

	while(std::cin >> B[1]) {
		std::cin >> B[2] >> B[3] >> B[4] >> B[5] >> B[6] >> B[7] >> B[8] >> B[9];
		int sum = B[1] + B[2] + B[3] + B[4] + B[5] + B[6] + B[7] + B[8] + B[9];		

		int min=2147483647, a;		
		//BCG
		if (sum - (B[1] + B[6] + B[8]) < min) {
			min = sum - (B[1] + B[6] + B[8]);
			a = 1;
		}
		//BGC
		if (sum - (B[1] + B[5] + B[9]) < min) {
			min = sum - (B[1] + B[5] + B[9]);
			a = 2;
		}
		//CBG		
		if (sum - (B[3] + B[4] + B[8]) < min) {
			min = sum - (B[3] + B[4] + B[8]);
			a = 3;
		}
		//CGB
		if (sum - (B[3] + B[5] + B[7]) < min) {
			min = sum - (B[3] + B[5] + B[7]);
			a = 4;
		}
		//GBC
		if (sum - (B[2] + B[4] + B[9]) < min) {
			min = sum - (B[2] + B[4] + B[9]);
			a = 5;
		}
		//GCB
		if (sum - (B[2] + B[6] + B[7]) < min) {
			min = sum - (B[2] + B[6] + B[7]);
			a = 6;
		}
		
		switch (a) {
			case 1: std::cout << "BCG " << min << std::endl; break;
			case 2: std::cout << "BGC " << min << std::endl; break;
			case 3: std::cout << "CBG " << min << std::endl; break;
			case 4: std::cout << "CGB " << min << std::endl; break;
			case 5: std::cout << "GBC " << min << std::endl; break;
			case 6: std::cout << "GCB " << min << std::endl; break;
		}
	}

	return 0;
}