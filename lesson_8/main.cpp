#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mtx;
mutex mtx2;

void Print() {
    mtx2.lock();
    this_thread::sleep_for(chrono::milliseconds(1));
 
    mtx.lock();

    for (int i = 0; i < 5; i++) {
        for (int i = 0; i < 10; i++) {
            cout << '*';
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        cout << endl;
    }
    cout << endl;

    mtx.unlock();
    mtx2.unlock();
}
void Print2() {
    mtx2.lock();
    this_thread::sleep_for(chrono::milliseconds(1));
 
    mtx.lock();

    for (int i = 0; i < 5; i++) {
        for (int i = 0; i < 10; i++) {
            cout << '#';
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        cout << endl;
    }
    cout << endl;
    
    mtx.unlock();
    mtx2.unlock();
}

int main() {
    setlocale(LC_ALL, "Russian");

    thread t1(Print);
    thread t2(Print2);


    t1.join();
    t2.join();

    return 0;
}