#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<float> len(n);
    std::vector<float> spd(n);
    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        int l, s;
        std::cin >> l >> s;
        len[i] += l + max_len;
        spd[i] = s;
        max_len += l;
    }

    float front(0), end(max_len);
    while (front + (max_len - end) < max_len) {
        float tmp, tmp2;
        {
            auto it = std::lower_bound(len.begin(), len.end(), front);
            std::size_t pos = std::distance(len.begin(), it);
            tmp = front;
            front += 1 * spd[pos];
        }
        {
            auto it = std::lower_bound(len.begin(), len.end(), end);
            std::size_t pos = std::distance(len.begin(), it);
            tmp2 = end;
            end -= 1 * spd[pos];
        }
        if (front + (max_len - end) > max_len) {
            front = tmp;
            end = tmp2;
            break;
        }
    }
    std::cout << front << std::endl;
}