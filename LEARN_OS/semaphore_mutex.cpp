#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mtx;
long long count = 0;

void task() {
    // mtx.lock();
    for (int i = 0; i < 1000000; i++) {
        count++;
    }
    // mtx.unlock();
}

int main() {
    thread t1(task);
    thread t2(task);

    t1.join();
    t2.join();

    cout << count << endl;
    return 0;
}
