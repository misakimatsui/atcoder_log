#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

int arr[10];
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> ok;
    std::vector<int> ng;
    for (int i = 0; i < 10; ++i) {
        char n;
        std::cin >> n;
        switch(n) {
            case 'o' : ok.push_back(i); break;
            case 'x' : ng.push_back(i); break;
        }
    }

    int cnt = 0;
    for (int a = 0; a < 10; ++a) {
        for (int b = 0; b < 10; ++b) {
            for (int c = 0; c < 10; ++c) {
                for (int d = 0; d < 10; ++d) {
                    bool isok = true;
                    for (auto x : ok) {
                        if (a != x && b != x && c != x && d != x) {
                            isok = false;
                        }
                    }
                    for (auto x : ng) {
                        if (a == x || b == x || c == x || d == x) {
                            isok = false;
                        }
                    }
                    if (isok) {
                        cnt++;
                    }
                }
            }
        }
    }
    std::cout << cnt << std::endl;
}