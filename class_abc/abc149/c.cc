#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int x){
    int i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int x; 
	cin >> x;

    int num  = x;
    while(1) {
        if (isPrime(num)) {
            break;
        }
        ++num;


    }

	std::cout << num << std::endl;
}