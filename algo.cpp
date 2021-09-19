#include <cmath>
#include <iostream>
#include <string>

int Sum(const std::string& s, int power) {

}

void decode(std::string& s) {
    int n = static_cast<int>(s.size());
    int no_parities = 1;
    while (no_parities < std::log2(n))
        ++no_parities;
    int error = 0;
    bool change = false;
    for (int i = 0; i < no_parities; ++i) {
        int count = 0;
        int pow2 = 1 << i;
        for (int j = pow2; j <= s.size(); j += 2 * pow2) {
            for (int index = j; index < j + pow2; ++index) {
                if (index - 1 >= static_cast<int>(s.size()))
                    break;
                count += s[index - 1] == '0' ? 0 : 1;
            }
        }
        count %= 2;
        if (count) {
            error += 1 << i;
            change = true;
        }
    }
    if (change) {
        s[error - 1] = s[error - 1] == '0' ? '1' : '0';
    }
    std::string ans(n - no_parities, '0');
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        if ((i & (i - 1)) != 0) {
            ans[j] = s[i - 1];
            ++j;
        }
    }
    std::cout << ans << '\n';
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
