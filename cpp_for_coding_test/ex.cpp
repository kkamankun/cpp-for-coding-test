#include <iostream>
#include <functional>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>

int main() {
    int T; // the number of test case
    scanf("%d", &T);

    int result = 0;
    int N, K; // (8 <= N <= 28)
    char c[28];
    std::string str;
    std::set<std::string, std::greater<std::string>> set;
    for (int test_i = 1; test_i <= T; ++test_i) {
        scanf("%d %d\n", &N, &K);
        const int length = N / 4;
        scanf("%s", c);
        for (int shift = 0; shift < N; shift++) {
            for (int i = 0; i < 4; i++) {
                str.clear();
                for (int j = 0; j < length; j++) {
                    str += c[(i * length + shift + j) % N];
                }
                set.insert(str);
            }
        }
        std::vector<std::string> vec(set.begin(), set.end());
        std::stringstream ss;
        unsigned long long int v;
        ss << std::hex << vec[K - 1];
        ss >> v;
        set.clear();
        printf("#%d %d\n", test_i, v);
    }
    return 0;
}