// A.SIGNLE FLAG
// #include <bits/stdc++.h>
// using namespace std;

// atomic<bool> turn{0};
// long long cnt = 0;

// void task(int id) {
//     for (int i = 0; i < 1000000; i++) {
//         cnt++;
//     }
//     turn = !id; // Toggle flag
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     thread t1([&]() {
//         while (turn != 0); // Busy wait
//         task(0);
//     });

//     thread t2([&]() {
//         while (turn != 1); // Busy wait
//         task(1);
//     });

//     t1.join();
//     t2.join();

//     cout << cnt << endl;
//     return 0;
// }

// B.PETERSON'S SOLUTOIN

#include <bits/stdc++.h>
using namespace std;

volatile bool flag[2] = {false, false}; 
volatile int turn = 0;
long long cnt = 0;

void task(int id) {
    for (int i = 0; i < 1000000; i++) {
        cnt++;
    }
}

void process(int id) {
    int other = 1 - id;
    flag[id] = true;
    turn = other;
    
    while (flag[other] && turn == other); // Busy wait
    
    task(id); // Critical section

    flag[id] = false; // Exit critical section
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    thread t1(process, 0);
    thread t2(process, 1);

    t1.join();
    t2.join();

    cout << cnt << endl;
    return 0;
}
