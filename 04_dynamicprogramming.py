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


print("Sum: ", addition(4))
print("Fac: ", factorial(1))
print("2 **:", tworaisedtopower(4))
print("Fib:", fibonacci(8))
print("Stairs: ", climbingStairs(7), "ways")
