// Multithreading is a feature that allows concurrent execution of two or more parts of a program for maximum utilization of the CPU. 
// Each part of such a program is called a thread. 
// So, threads are lightweight processes within a process.


// To start a thread we simply need to create a new thread object and pass the executing code to be called (a callable object) into the constructor. Once the object is created a new thread is launched which will execute the code specified in callable. A callable can be any of the five:
// A Function Pointer
// A Lambda Expression
// A Function Object
// Non-Static Member Function
// Static Member Function


#include <iostream>
#include <thread>

static bool flag = true;

void dowork(int x, int y) {
    std::cout << "The thread id is = " << std::this_thread::get_id() << '\n';

    using namespace std::literals::chrono_literals;         // namespace within namespace within namespace
    while(flag) {
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s);  // the thread sleeps for 1 second every time this line runs.
    }
}

int main() {
    int y = 1;
    std::thread worker(dowork, 2, y);       // creates a new thread named worker with dowork callable. This thread runs the function dowork on a separate thread.

    // now ideally, if dowork would have been running on this current thread only, we wouldn't have been able to
    // press a keystroke and make flag = false and break out of loop.
    // We would explicitly need to break out of loop then.
    // But because of multithreading, that dowork is running on a new thread, and I can press a key and
    // make flag = false on this current thread thus ending the while loop(and dowork) of that new thread.
    std::cin.get();                 // waits for keystroke
    std::cout << "The thread id is = " << std::this_thread::get_id() << '\n';       // this thread_id is different from thred_id of that new thread.
    flag = false;                   // making it false, breaks off the while loop in dowork
    worker.join();                  // joins that new thread to the current thread to make one single thread.
    std::cout << "Finished\n";
}