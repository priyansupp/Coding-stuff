def handle_legacy(func):
    print("Initialized decorator handle_legacy")
    def execute_handle(*args, **kwargs):
        print("Before func in execute_handle")
        x = list(args)
        x.append(100)
        func(x)
        print("After func in execute_handle")
        # return -1
    return execute_handle

def new_decor(func):
    print("Initialized decorator new_decor")
    def execute_new(*args, **kwargs):
        print("Before func in execute_new")
        func(*args)
        print("After func in execute_new")
        # return -1
    return execute_new


# @handle_legacy
# @new_decor
def create_instance(x):
    print(f"Created something: {x}")


create_instance = new_decor(create_instance)
print(create_instance.__name__)

create_instance = handle_legacy(create_instance)    # -> similar to using decorator @handle_legacy on create_instance
print(create_instance.__name__)

create_instance(17)


# x(11)
# x(12)

