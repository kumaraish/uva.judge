/**
 * AC - 0.037 secs
 * Further optimizations after simple cache -
 * Replaced division / multiplication with bit operators
 * No improvements in speed :-(
 */

#include <iostream>
#include <stdio.h>

int Table[1000000] = {0};

int getCycleLen(int k) {
    int len = 1;

    while (k > 1) {
        if (k & 0x0001) {
            k = (k + k + k) + 1;
        } else {
            k = k >> 1;
        }
        len++;
    }

    return len;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("100.in", "r", stdin);
#endif

    int i, j, maxCycleLen;

    while (std::cin >> i >> j) {
        int orig_i = i;
        int orig_j = j;
        if (i > j) {
            std::swap(i, j);
        }

        maxCycleLen = 0;
        for (int k = i; k <= j; k++) {

            if (Table[k] == 0) {
                Table[k] = getCycleLen(k);
            }

            maxCycleLen = std::max(Table[k], maxCycleLen);
        }

        std::cout << orig_i << " " << orig_j << " " << maxCycleLen << std::endl;
    }

    return 0;
}