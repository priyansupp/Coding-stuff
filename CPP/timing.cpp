#include <iostream>
#include <chrono>

// using std::chrono::high_resolution_clock = std::chrono::steady_clock;    declaration in chrono

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "It took " << duration.count() * 1000.0f << " ms\n";
    }
};

void f1(int n) {
    for(int i = 0; i < n; i++) {
        std::cout << "Hello\n";
    }
}

void f2(int n) {
    Timer t;            // just declare this object for any scope you wanna measure time for. It'll get destroyed because of object scope and output the exact time.
    for(int i = 0; i < n; i++) {
        std::cout << "Hello" << std::endl;
    }
}

int main() {
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    f1(100);
    auto end = std::chrono::high_resolution_clock::now();       // can use auto directly
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time required for execution = " << duration.count() * 1000.0f << " ms\n";

    f2(100);
    // Time for f2 will be more because we used std::endl which is an endline function which adds newlines to the stream and also flushes the buffer each time it is used
    
    // to use Timer for block of code in between, use the empty scope
    {
        Timer t;
        for(int i = 0; i < 10000000; i++);
    }
    
    
    return 0;
}

