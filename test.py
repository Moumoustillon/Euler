from functools import reduce
from operator import mul


def solve():
    """ Compute the answer to Project Euler's problem #40 """

    upper_limit = 200000  # large enough s.t. the total string length exceeds the highest index

    fractional_string = "".join(["{}".format(i + 1) for i in range(upper_limit)])  # build the string representation

    # Extract the relevant d_i values
    indices = [1, 10, 100, 1000, 10000, 100000, 1000000]
    digits = [fractional_string[i - 1] for i in indices]  # Python using 0-based indices

    for i in range (0,7) :
        print(fractional_string[indices[i]-1])

    # Multiply each d_i together to get the answer
    answer = reduce(mul, map(int, digits))
    

    return answer


expected_answer = 210
print(solve())