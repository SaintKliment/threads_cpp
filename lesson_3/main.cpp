#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


void DoWork(int &a) {
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    cout << "ID THREAD = " << this_thread::get_id() << "\t==========\t" << "START work" << "\t==========" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    
    a *= a;

    cout << "ID THREAD = " << this_thread::get_id() << "\t==========\t" << "END work" << "\t==========" << endl;
}


int main() {
    setlocale(LC_ALL, "Russian");
    
    int q = 5;
    thread th(DoWork, ref(q));
    th.detach();

    bool tof = true;
    for(size_t i = 0; tof == true; i++){
        cout << "ID thread: " << this_thread::get_id() << "\t MAIN\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        if (i == 25) {
            tof = false;
        }
    }

    // th.join();
    cout << q << endl;


    return 0;
}