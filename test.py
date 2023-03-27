def is_pandigital(n):
    """Returns True if n is pandigital, i.e., if it contains all the digits from 1 to 9 exactly once."""
    return sorted(str(n)) == list('123456789')

largest_pandigital = 0

# 3-digit integers
for i in range(912, 988):
    concatenated_product = i * 100002  # product of i and (1,2)
    if is_pandigital(concatenated_product):
        largest_pandigital = max(largest_pandigital, concatenated_product)
    concatenated_product = i * 100020  # product of i and (1,2,3)
    if is_pandigital(concatenated_product):
        largest_pandigital = max(largest_pandigital, concatenated_product)
    concatenated_product = i * 100200  # product of i and (1,2,3,4)
    if is_pandigital(concatenated_product):
        largest_pandigital = max(largest_pandigital, concatenated_product)
    concatenated_product = i * 102003  # product of i and (1,2,3,4,5)
    if is_pandigital(concatenated_product):
        largest_pandigital = max(largest_pandigital, concatenated_product)
    concatenated_product = i * 120003  # product of i and (1,2,3,4,5,6)
    if is_pandigital(concatenated_product):
        largest_pandigital = max(largest_pandigital, concatenated_product)
    concatenated_product = i * 120300  #

print(largest_pandigital)
