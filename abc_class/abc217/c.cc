#include <iostream>
#include <vector>

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[vec[i]-1] = i;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] + 1 << " ";
    }
    std::cout << std::endl;

}