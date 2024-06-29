#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


void work(int a, int b ) {
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "==========\t" << "START work" << "\t==========" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    int res = a + b;
    cout << "==========\t" << "ANSWER = " << res << "\t==========" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "==========\t" << "END work" << "\t==========" << endl;
}


int main() {
    setlocale(LC_ALL, "Russian");
    
    thread th(work, 3, 2);


    bool tof = true;
    for(size_t i = 0; tof == true; i++){
        cout << "ID thread: " << this_thread::get_id() << "\t MAIN\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        if (i == 25) {
            tof = false;
        }
    }
    th.join();


    return 0;
}