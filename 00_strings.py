# # """
# #     Input: s = "the sky is blue"
# #     Output: "blue is sky the"
# # """

# # str = "     the sky is blue   x          "
# # # s = s.split(" ")
# # print(str)

# # i = 0
# # l = len(str)

# # stack = []
# # print(l)

# # s = ""
# # while i < l:
# #     while str[i] == " ":
# #         i += 1
# #     start = i

# #     while str[l - 1] == " ":
# #         l -= 1

# #     while str[i] != " ":
# #         s += str[i]
# #         i += 1
# #     stack.append(s)
# #     s = ""
# # reverse = []
# # while len(stack):
# #     reverse.append(stack.pop())

# # print(" ".join(reverse))
# # # print(str[start:end])

# # # print(stack)
# # #     if str[i] == " ":
# # #         stack.append(s)
# # #         s = ""

# # #     s += str[i]

# # #     i += 1

# # #     # print(s)
# # # print(stack)

# # sequence = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# # sliced_sequence = sequence[::-1]
# # print(sliced_sequence)

# s = "hello"
# # Output: "holle"


# def isVowel(s):
#     if s in ["a", "e", "i", "o", "u"]:
#         return True
#     return False


# s = list(s)
# i, l = 0, len(s)
# print(i, l)


# def swap(a, b):
#     a, b = b, a
#     return a, b


# # print(swap("a", "b"))
# # s = "aei"
# while i < l:
#     # print(s, i, l)
#     if isVowel(s[i]) and isVowel(s[l - 1]):
#         s[i], s[l - 1] = swap(s[i], s[l - 1])
#         # print("swaped: ", s, i, l)

#         i += 1
#         l -= 1
#     elif not isVowel(s[i]):
#         i += 1
#     elif not isVowel(s[l - 1]):
#         l -= 1

# print(s)


VOWELS = set("aeiouAEIOU12312312")
print(VOWELS)
