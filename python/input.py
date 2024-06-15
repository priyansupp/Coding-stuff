# x = input("type something: ")
# print(x, type(x))

# x = int(input("type something: "))    #won't accept any input other than int
# print(x, type(x))

# x = float(input("type something: "))  # will accept decimal and int
# print(x, type(x))

# lst = []                              # empty list

# n = int(input("enter number of elements: "))

# for i in range(n):
#     x = int(input())                  # EACH NEW INPUT MUST BE ON A NEW LINE
#     lst.append(x)

# for i in lst:
#     print(i)

s = input("type something: ")               # takes input as string
print(s, type(s))
for i in s:
    print(i, type(i))
print(s[2])

l = list(input("type something: "))         # forms a list of each character typed
print(l, type(l))
for i in l:
    print(i, type(i))
print(l[2])

lt = input("type something: ").split()      # makes a list of string, spilts with a whitespaces(space, tab)
print(lt, type(lt))
for i in lt:
    print(i, type(i))
print(lt[2])

ltt = input("type something: ").split('#')   # makes a list of string, spilts with a '#' in input
print(ltt, type(ltt))
for i in ltt:
    i = int(i)                              # int() typecasts to int
    print(i, type(i))
print(ltt[2])


