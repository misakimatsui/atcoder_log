#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;


int arr[125];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        arr[c]++;
    }
    for (int i = 97; i < 123; ++i) {
        for (int j = arr[i]; 0 < j; --j) {
            std::cout << static_cast<char>(i);
        }
    }
    std::cout << '\n';

    for (int i = 122; 96 < i; --i) {
        for (int j = arr[i]; 0 < j; --j) {
            std::cout << static_cast<char>(i);
        }
    }
    std::cout << '\n';



}