#include <set>
#include <iostream>

int main(void) {
    std::set<int> st;

    st.insert(5);
    st.insert(0);
    for (auto it : st) {
        std::cout << it << std::endl;
    }


}