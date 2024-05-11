# def recursion(n):
#     return 1 if n == 1 else recursion(n - 1) + n


"""
3-steps

- base case
- small calc or recurisive call
- recursive call or small calc
"""


def addition(n):
    if n == 1:
        return 1
    return addition(n - 1) + n


def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)


def tworaisedtopower(n):
    if n == 0:
        return 1

    return tworaisedtopower(n - 1) * 2


def fibonacci(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)


def climbingStairs(n):
    if n <= 2:
        return n
    return climbingStairs(n - 1) + climbingStairs(n - 2)


def isPalindomeOneHelper(str, i):
    if str[i] != str[(len(str) - 1) - i]:
        return False
    if i >= (len(str) // 2):
        return True
    return isPalindomeOneHelper(str, i + 1)


def isPalindomeOne(str):
    if isPalindomeOneHelper(str, 0):
        print("palindrome")
        return True
    else:
        print("NOT")


def isPalindromeTwohelper(str, start, end):
    if start >= end:
        return True
    if str[start] != str[end]:
        return False

    return isPalindromeTwohelper(str, start + 1, end - 1)


def isPalindromeTwo(str):
    # print(str)
    return isPalindromeTwohelper(str, 0, len(str) - 1)


def reverseArrayOne(arr, i):
    if i > len(arr) // 2 - 1:
        print(arr)
        return

    # print(arr)

    # print(i, ":", len(arr) - 1 - i)
    swap = arr[i]
    arr[i] = arr[len(arr) - 1 - i]
    arr[len(arr) - 1 - i] = swap
    return reverseArrayOne(arr, i + 1)


def reverseArraytwohelper(arr, start, end):
    if start >= end:
        return

    # swap = arr[start]
    # arr[start] = arr[end]
    # arr[end] = swap
    arr[start], arr[end] = arr[end], arr[start]
    start += 1
    end -= 1

    return reverseArraytwohelper(arr, start, end)


def reverseArraytwo(arr):
    print(arr)
    start = 0
    end = len(arr) - 1
    reverseArraytwohelper(arr, start, end)
    print(arr)


# subseqeuences and powersets
# even empty "" sting is a sub sequence
#  FOR 12345 ,,   : 123(continuous/contigeous) is sub array and sub sequence
# while 125(non continuous) is just subsequence


def dhelper(arr, idx, curr, result):
    if idx >= len(arr):
        return

    curr.append(arr[idx])
    # print(curr)
    dhelper(arr, idx + 1, curr, result)


def dpowerset(arr):
    # in psequence we don't consider empty set
    # here sub sequences are 7.. but it is not considered as sequence  =  7 subsequences
    # powerset = 8 subsets
    result = []
    curr = []
    dhelper(arr, 0, curr, result)  # to add subsets t

    return result


def helper(str, idx, curr, result):
    # print(curr)
    if idx >= len(str):
        result.append(curr)
        print(result)
        return

    helper(str, idx + 1, curr + str[idx], result)
    helper(str, idx + 1, curr, result)


def powerset(str):
    curr = ""
    result = []
    helper(str, 0, curr, result)
    # print(result)


# #######################################################################################################################################################


# print("Sum: ", addition(4))
# print("Fac: ", factorial(1))
# print("2 **:", tworaisedtopower(4))
# print("Fib:", fibonacci(8))
# print("Stairs: ", climbingStairs(7), "ways")
# print(f"isPalindome? ", isPalindromeTwo("abscba"))

powerset("abc")

# reverseArraytwo([1, 2, 3, 4, 5, 6, 7])
