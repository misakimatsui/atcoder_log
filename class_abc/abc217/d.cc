#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>


int main(void) {

    int l, q;
    std::cin >> l >> q;

    std::set<int> st;
    st.insert(0);
    st.insert(l);
    int c, val;
    for (int i = 0; i < q; ++i) {
        std::cin >> c >> val;
        if (c == 1) {
            st.insert(val);
        }
        else {
            auto it = st.lower_bound(val);
            std::cout << (*it - *prev(it)) << std::endl;
        }
    }
}