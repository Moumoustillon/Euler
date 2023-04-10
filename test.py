from math import sqrt

def is_pentagonal(n): return (1+sqrt(1+24*n))%6==0

i=0
while True:
    i+=1
    k = i*(3*i-1)//2
    for v in range(1,i):
        j = v*(3*v-1)//2
        if is_pentagonal(k-j) and is_pentagonal(k+j) :
            print(k-j)
            print(k)
            print(i)
            print(j)
            print(v)
            break
    else:
        continue
    break