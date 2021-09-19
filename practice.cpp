#include <iostream>
#include <vector>
#include <valarray>

void decode(std::string& s) {
    char static rem[1000000] = {};
    int no_parities = 0, n = s.size();
    for (int b = 1; b <= n; b *= 2) {
        no_parities++;
    }
    std::vector<int> decoded;
    int error = 0;
    for (int parity_n = 0; parity_n < no_parities; ++parity_n) {
        int pow2 = (1 << parity_n) - 1;
        int count = 0;
        for (int j = pow2; j < n; j += 2 * pow2) {
            for (int sss = j; sss < j + pow2; sss++) {
                count += s[sss] - '0';
            }
        }
        error += count % 2;
    }
    int pos_error = 0;
    if (error) {
        if (s[error - 1] == '1') {
            s[error - 1] = '0';
        } else {
            s[error - 1] = '1';
        }
        for (int i = 0; i < n; i++) {
            if (i == ((int) pow(2, pos_error) - 1)) {
                pos_error++;
            } else {
                rem[pos_error] = s[i];
                pos_error++;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i == ((int) pow(2, pos_error) - 1)) { pos_error++; }
            else {
                rem[pos_error] = s[i];
                pos_error++;
            }
        }
    }
    std::cout << rem << "\n";
}

int main() {
    int t = 1;
//    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        decode(s);
    }
}
//