import os

n=int(input())

tmp = n / 10.0;
if 0 < tmp:
    print(int(tmp))
elif tmp.is_integer():
    print(int(tmp))
else :
    print(int(tmp-1))