#include <iostream>
#include <queue>

// a semaphore maintains a waiting queue of processes that have asked to execute their critical section.
// when wait() is called, the process is blocked using block() and enters the queue.
// when signal() is called, the process at beginning of the queue is popped and executed using wakeup()


class Process {
public:
    void execute() {
        for(int i = 0; i < 10000; i++);
    }
};

void wakeup(Process &p) {}


// All increment or decrement operations on semaphore value is atomic
struct semaphore {
    int value;
    std::queue<Process>list;

    semaphore(int n) : value(n) {}

    // actual implementation of wait() and signal() in CPU. It does not involves busy wait, because it consumes resources of CPU to keep checking for busy wait
    // instead we can use a waiting queue to keep track of processes waiting to enter critical section
    // We save the PCB in the queue and execute from the PCB once that process is allowed to enter critical section
    void wait(Process p) {
        value--;
        if(value < 0) {
            list.push(p);
            // block();       // better than busy wait while loop, just block or sleep the process
            // sleep();
        }
    } 
    void signal() {
        value++;
        if(value >= 0) {
            Process p = list.front();
            list.pop();
            wakeup(p);            // wakeup step => put the process in ready queue starting from its PCB state
        }
    }

    // inefficient implementation of wait/signal, takes CPU resources to implement busy wait
    void wait2() {
        while(value <= 0);       // busy wait
        value--;
    }
    void signal2() {
        value++;
    }
};

// In second implementation of wait2() and signal2(), it is just for understanding. The wait2() functions does not terminate until the process is allowed to enter CS, once it terminates, the line following wait2() in the code of process starts executing. Very bad implementation, busy wait eats up CPU resources.

// In first implementation of wait() and signal(), is actual implementation in os. The wait() function saves the PCB(like the line in code from where it should start again) in list if the process cannot enter CS and once signal() is called, it removes processes one by one from queue and starts executing them again from the point saved in PCB(like the line of code). Very efficient implementation.



int main() {
    Process p1, p2;
    semaphore s(1);

    // CODE FOR p1:
    {
        for(int i = 0; i < 1000; i++);
        // Critical section
        s.wait(p1);

        // do some CS work

        s.signal();
        // Critical section over

        // Remainder section for p1
    }
    // p1 over

    // CODE FOR p2:
    {   
        for(int i = 0; i < 1000; i++);
        // Critical section
        s.wait(p2);

        // do some CS work

        s.signal();
        // Critical section over

        // Remainder section for p2
    }
    // p2 over

    return 0;
}
