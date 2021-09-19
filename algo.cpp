#include <iostream>
#include <vector>
#include <complex>


void decode(std::string& encyptedRedBitsq) {
    char static rem[1000000] = {};
    int n = encyptedRedBitsq.size();
    int no_of_extra = 0;
    for (int b = 1; b <= n; b *= 2) {
        no_of_extra++;
    }
    int ss = 0, error = 0, pos_of_orisig = 0, pos_of_redsig = 0;

    for (int i = 0; i < no_of_extra; i++) {
        int count = 0;
        int position = (int) pow(2, i);
        ss = position - 1;
        while (ss < n) {
            for (int sss = ss; sss < ss + position; sss++) {
                if (encyptedRedBitsq[sss] == '1')
                    count++;
            }
            ss = ss + 2 * position;
        }
        if (count % 2 != 0) { error += position; }
    }

    if (error != 0) {
        printf("Error detected and corrected!\n");
        if (encyptedRedBitsq[error - 1] == '1') { encyptedRedBitsq[error - 1] = '0'; }
        else { encyptedRedBitsq[error - 1] = '1'; }
        for (int i = 0; i < n; i++) {
            if (i == ((int) pow(2, pos_of_orisig) - 1)) { pos_of_orisig++; }
            else {
                rem[pos_of_redsig] = encyptedRedBitsq[i];
                pos_of_redsig++;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i == ((int) pow(2, pos_of_orisig) - 1)) { pos_of_orisig++; }
            else {
                rem[pos_of_redsig] = encyptedRedBitsq[i];
                pos_of_redsig++;
            }
        }
    }
    std::cout << rem << "\n";
}

//  1001010110
//  1001010110

int main() {
    int t = 1;
//    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        decode(s);
    }
}
