#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main(void) {
    std::vector<int> vec{1,2,3,4};
    std::priority_queue<int, std::vector<int>, std::greater<int>> que;
    std::cout << que.top() << std::endl;
}