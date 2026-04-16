#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {

        int n = binary.size();

        int firstZero = -1;
        int zeroCount = 0;

        for (int i = 0; i < n; i++) {
            if (binary[i] == '0') {
                zeroCount++;
                if (firstZero == -1)
                    firstZero = i;
            }
        }

        // no zero
        if (zeroCount <= 1)
            return binary;

        string result(n, '1');

        int index = firstZero + zeroCount - 1;
        result[index] = '0';

        return result;
    }
};
