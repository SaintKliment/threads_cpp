#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int Sum(int a, int b) {
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "start and thread id = " << this_thread::get_id() << endl;
    
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "end and thread id" << this_thread::get_id() << endl;
    
    return a + b;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int result;
    thread th([&result]() { result = Sum(3, 6); });

    for(size_t i = 0; i < 15; i++){
        cout << "ID thread: " << this_thread::get_id() << "\t MAIN\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join();
    cout << "result = " << result << endl;

    return 0;
}