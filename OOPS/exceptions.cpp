#include <iostream>
#include <stdexcept>    // all the standard exceptions defined in this class
#include <exception>
#include <string.h>     // for strcpy() in c style strings
using namespace std;

// Making a custom exception class from base class "exception", requires <exception> library
class CustomException : public exception{
private:
    char* error_message;
public:
    CustomException(const char* error) {
        strcpy(error_message, error);
    }
    // noexcept here makes sure that this function itself cannot return exception and must always return const char*
    inline const char* what() const noexcept {  // important to write "noexcept"
        return error_message;
    }
};


// optional to explicitly label what exception the function will throw. Good practice
void fun(int a, int b) throw(char, int) {
    if(a == 0) {
        throw 'a';
    } 
    if(b == 0) {
        throw 5;
    }
}

// int id = 0;


int main() {

    // INTRODUCTION
    // does not require the <stdexcept> library
    char c = 'a';
    try {
        cout << "Try block\n";
        throw c;
    } catch(int x) {        // no implicit type conversion. char c won't be typecasted to int hence this catch block won't run
        cout << "Caught int " << x << '\n';
    } catch(char) {         // no param name, if we don't wanna use it
        cout << "Caught char\n";
    } catch(...) {          // for all types of errors
        // Catch all must be the last catch block in a particular throw-catch statement. Else compilation error.
        cout << "Catch all block\n";
    }

    // GENERAL EXCEPTIONS
    int x = -1;
    try {
        cout << "Try\n";
        try {
            cout << "Nested Try.\n";
            if(x < 0) {
                throw "Negative value exception";
                cout << "After nested throw.\n";
            }
            cout << "After throw\n";
        } catch (const char* e) {
            // Handle exception partially
            cout << "Nested catch. " << e << '\n';
            throw;  // Rethrowing the exception.
        }
    } catch(const char* e) {
        // Handle rest of the exception
        cout << "Catch. " << e << '\n';
    }


    // STANDARD EXCEPTIONS
    // requires <stdexcept> for throwing specific errors
    long y = (long)1e10;
    try {
        if(y < 0) {
            throw std::invalid_argument("This value of y is invalid.");
        } else if (y > (long)1e9) {
            throw std::overflow_error("y exceeds the bound for int type.");
        }
    } catch(std::invalid_argument& e) {     // derived class from std::exception
        cout << e.what() << "\n";           // every derived class overrides what() method
    } catch(std::exception& e) {            // base class std::exception
        // NOTE: Because base class exception is before derived class, hence overflow_error will be caught by the base class std::exception only and never reach std::overflow_error catch block.
        // Compiler generates warnings but compiles
        cout << "Base class exception block. " << e.what() << "\n";
    } catch(std::overflow_error& e) {
        cout << e.what() << "\n";
    }


    // CUSTOM EXCEPTIONS
    // requires <exception> library to build custom exception from base class exception
    try {
        if(c == 'a') {
            throw CustomException("This character should not be a.");
        }
    } catch(CustomException& e) {
        cout << "CustomException error. " << e.what() << '\n';
    }

    // FUNCTIONAL EXCEPTIONS
    try {
        fun(2, 0);
    } catch (int i) {
        cout << i << '\n';
    } catch(char ch) {
        cout << ch << '\n';
    }


    // EXCEPTIONS IN CLASSES AND OBJECTS
    // local class
    static int id1 = 0;
    class A{
        // static int id = 0;   // local classes cannot have static members
        int id = 0;
    public:
        A() { 
            cout << "Constructor " << id1 << '\n'; 
            this->id = id1++; 
        }
        ~A() { cout << "Destructor " << this->id << '\n'; }
    };
    try {
        A a[2];
        // before error is thrown, all the objects inside try are destroyed.
        // Objects destroyed in reverse order of their creation.
        throw 1;
    } catch(int x) {
        cout << x << '\n';
    }

    return 0;
}

// IMPORTANT POINTS TO REMEMBER:
// 1. If an exception is thrown but not caught anywhere, the program would compile but when the exception is thrown the program ends abruptly.
// 2. No implicit type conversion.
// 3. Compiler doesn't checks for catch blocks
// 4. void fun(int, int) would be compile fine but a better way to write is void fun(int, int) throw(char, int) {}

// std::exception	Exception and parent class of all standard C++ exceptions.
// std::bad_alloc	Generally thrown by new.
// std::bad_cast	Generally thrown by dynamic_cast.
// std::bad_typeid	Generally thrown by typeid.
// std::bad_exception	Useful device to handle unexpected exceptions.
// std::logic_failure	Can be detected by reading code.
// std::runtime_error	Cannot be detected by reading code.
// std::domain_error	Thrown when using a mathematically invalid domain.
// std::invalid_argument	Thrown when using invalid arguments.
// std::length_error	Thrown when a large std::string is created.
// std::out_of_range    Thrown by the at method.
// std::overflow_error	Thrown when a mathematical overflow occurs.
// std::range_error	Thrown when attempting to store an out-of-range value.
// std::underflow_error    Thrown when a mathematical underflow occurs.






