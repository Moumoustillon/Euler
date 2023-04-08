from itertools import permutations
datas=list(map(lambda j: ''.join(j) ,list(permutations('0123456789'))))
ans=0
for number in datas:
    if int(number[3])%2==0 and int(number[5])%5==0:
      if int(number[1:4])%2==0 and int(number[2:5])%3==0 and int(number[3:6])%5==0 and int(number[4:7])%7==0 and int(number[5:8])%11==0 and int(number[6:9])%13==0 and int(number[7:10])%17==0:
          ans+=int(number)
print(ans)
