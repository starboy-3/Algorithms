#include <iostream>
#include <vector>
#include <valarray>

char *parityRemove(int no_of_extra, int ltot, char *encyptedRedBitsq) {
    char static rem[1000000] = {};
    int ss = 0, sss = 0, error = 0, pos_of_orisig = 0, pos_of_redsig = 0;
    // checking whether there are any errors
    for (int i = 0; i < no_of_extra; i++) {
        int count = 0, value = 0;
        int position = (int) pow(2, i);
        ss = position - 1;
        while (ss < ltot) {
            for (sss = ss; sss < ss + position; sss++) {
                if (encyptedRedBitsq[sss] == '1')
                    count++;
            }
            ss = ss + 2 * position;
        }
        if (count % 2 != 0) {
            error += position;
        }
    }

    // navigating to the errornous bits & correct them

    if (error != 0) {
        printf("Error detected and corrected!\n");
        if (encyptedRedBitsq[error - 1] == '1') { encyptedRedBitsq[error - 1] = '0'; }
        else { encyptedRedBitsq[error - 1] = '1'; }
        for (int i = 0; i < ltot; i++) {
            if (i == ((int) pow(2, pos_of_orisig) - 1)) { pos_of_orisig++; }
            else {
                rem[pos_of_redsig] = encyptedRedBitsq[i];
                pos_of_redsig++;
            }
        }
    }

        // removing the excessive parity bits of the sequences without the errors
    else {
        for (int i = 0; i < ltot; i++) {
            if (i == ((int) pow(2, pos_of_orisig) - 1)) { pos_of_orisig++; }
            else {
                rem[pos_of_redsig] = encyptedRedBitsq[i];
                pos_of_redsig++;
            }
        }
    }
    return rem;
}

int main() {
    int t = 1;
//    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        solve(s);
    }
}