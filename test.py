def coinCounts(target,value,*rest):
    if not rest: return 0 if target % value else 1    # Only one coin value
    return sum( coinCounts(target-used,*rest)         # Total of ways using
                for used in range(0,target+1,value) ) # varying numbers of the first coin value


answer = coinCounts(200,*[1,2,5,10,20,50,100,200])
print(answer)

def function(*arg):
    print (type(arg))
    for i in arg:
        print (i)

print(function(5))