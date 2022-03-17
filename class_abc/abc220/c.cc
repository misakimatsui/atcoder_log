#include <iostream>
#include <vector>

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    long int n;
    std::cin >> n;
    std::vector<long int> vec(n);
    long int sum = 0;
    for (long int i = 0; i < n; ++i) {
        long int v;
        std::cin >> v;
        sum += v;
        vec[i] = sum;
    }
    long int index = 0;
    std::cin >> index;

    long int ans = 0;
    auto it = std::lower_bound(vec.begin(), vec.end(), index % vec.back());
    auto pos = std::distance(vec.begin(), it);

    ans =  (index / vec.back()) * n + pos + 1;
    if (*it == index % vec.back()) {
        ans++;
    }
    std::cout << ans << std::endl;
}