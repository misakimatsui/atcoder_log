import os

n=int(input())

left = 1
right = 9
ans = 0
cnt = 1
mod = 998244353

while (left <= n):
    l = min(right, n)
    nn = l - left + 1
    ans += (nn * (1 + nn)) / 2

    
    right = pow(10, cnt) * 9 + right
    cnt += 1
    left *= 10

print(int(ans%mod))