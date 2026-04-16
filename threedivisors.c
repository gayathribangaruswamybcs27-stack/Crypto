#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int x) {
    if (x < 2) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

bool isThree(int n) {
    int root = sqrt(n);

    // check perfect square
    if (root * root != n)
        return false;

    // check if root is prime
    return isPrime(root);
}

