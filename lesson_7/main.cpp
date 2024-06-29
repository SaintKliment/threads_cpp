#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mtx;

void Print(char ch) {
    this_thread::sleep_for(chrono::milliseconds(2000));

    {lock_guard<mutex> guard(mtx); // к данной функции доступ только для одного потока

    for (int i = 0; i < 5; i++) {
        for (int i = 0; i < 10; i++) {
            cout << ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;}
    

    this_thread::sleep_for(chrono::milliseconds(2000));
}

int main() {
    setlocale(LC_ALL, "ru");

    thread t1(Print, '*');
    thread t2(Print, '#');
    thread t3(Print, '@');

    t1.join();
    t2.join();
    t3.join();

    // Print('*');
    // Print('#');

    return 0;
}