#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <string>
#include <random>
#include <unordered_map>
#include <cstdint>
#include <vector>
#include <time.h>


#define K 5

void bin(uint32_t n) {
    if (n > 1)
        bin(n/2);

    printf("%d", n % 2);
}

using namespace std;
int main() {
    vector<int> v;
    srand(time(NULL));

    // Create random
    v.reserve(K);
    for (int i = 0; i < K; i++) {
        v.push_back(rand() % 2);
    }

    // Print vector
    cout << "***Print vector of bits***" << endl;
    for (int i = 0; i < K; i++) {
        cout << "|" << v[i] << "|";
    }
    cout << endl;
    cout << endl;

    uint32_t concat = 0;
    for (int i = 0; i < K; i++)
        concat = (concat << 1) | v[i];

    cout << "+++Print concated bits+++\n";
    cout << "|";
    bin(concat);
    cout << "|" << endl;
    return 0;
}
