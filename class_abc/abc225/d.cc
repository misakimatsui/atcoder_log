#include <vector>
#include <iostream>
#include <algorithm>

struct Train {
    int b;
    int f;
};

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;

    std::vector<int> front(n+1, -1);
    std::vector<int> back(n+1, -1);
    std::vector<std::vector<int>> vec;

    while (q--) {
        int query, x, y;
        std::cin >> query;
        if (query == 1) { 
            std::cin >> x >> y;
            back[x] = y;
            front[y] = x;
        }
        else if (query == 2) {
            std::cin >> x >> y;
            back[x] = -1;
            front[y] = -1;
        }
        else {
            std::cin >> x;
            std::vector<int> tmp;
            bool isEnd = false;
            bool isFront = false;

            while (!isFront) {
                if (front[x] == -1) {
                    isFront = true;
                }
                else {
                    x = front[x];
                }
            }

            while (!isEnd) {
                tmp.push_back(x);
                if (back[x] == -1) {
                    isEnd = true;
                }
                else {
                    x = back[x];
                }
            }
            vec.push_back(tmp);
        }
    }
    for(auto Y : vec) {
        std::cout << Y.size() << " ";
        for (auto X : Y) {
            std::cout << X << " ";
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}