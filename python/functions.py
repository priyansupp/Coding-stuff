def f(args):
    for i in args:
        if(i == 3):
            pass        # works just like continue
        print(i)

print("list")
f([])                   # single argument
f([2])                  # single argument
f([3,2,5])              # single argument
print("dictionary")
f({})                   # single argument
f({3})                  # single argument
f({2,5,7,3,2})          # single argument
print("tuple")
#f((7))                 # is not iterable(single element in tuple)
f((3,5,2))              # single argument

# *args means we can pass arbitrary number of arguments to the function. A list is one argument, we can pass multiple number of lists

def myfunc(*args):
    for i in args:
        print(i)
    print(args[1])      # will show error if less that 2 arguments are passed
    print("**END**")

myfunc(3,2,4,6)         # 4 arguments passed(not a list, tuple, dictionary)
myfunc([], [2],[4],[3,4])   # 3 arguments passed(a list with n elements is only 1 argument passed)
myfunc({}, {3},{2,4,1},{6,4,2,7})   # simple dictionary without (key, value) pair
myfunc((), (3), (5,2,6)) # tuple is directly getting printed, without iterating over, so no error

# to pass dictionary/(key, value) pair, we use keyword arguments(kwargs)

def newf(**kwargs):
    for i in kwargs:       # i is key and kwargs[i] is corresponding value
        print(i, kwargs[i])

newf(name = "priyanshu", age = 20)




