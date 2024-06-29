#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class MyClass {
public:
    void DoSomethingWork() {
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    cout << "ID THREAD = " << this_thread::get_id() << "\t==========\t" << "START work" << "\t==========" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "ID THREAD = " << this_thread::get_id() << "\t==========\t" << "END work" << "\t==========" << endl;
    }

    void DoWork(int a) {
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    cout << "ID THREAD = " << this_thread::get_id() << "\t==========\t" << "START work" << "\t==========" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "ID THREAD = " << this_thread::get_id() << "\t==========\t" << "END work" << "\t==========\nanswer = " << a << endl;
    }

    int Sum(int a, int b) {
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "start and thread id = " << this_thread::get_id() << endl;
    
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "end and thread id" << this_thread::get_id() << endl;
    
    return a + b;
    }


};

int main() {
    setlocale(LC_ALL, "ru");

    int result;
    MyClass m;
    
    // thread t(&MyClass::DoWork, m, 6); // 2.1 variant
    thread t([&]() { m.DoWork(3);}); // 2.2 variant

    // thread t([&]() { m.DoSomethingWork(); }); // 2.1 variant
    // thread t(&MyClass::DoSomethingWork, m); // 2.2 variant

    // thread t([&]() {result = m.Sum(3, 6);}); // 1 variant

    for(size_t i = 0; i < 15; i++){
        cout << "ID thread: " << this_thread::get_id() << "\t MAIN\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    t.join();
    // cout << result << endl; // 1 variant

    return 0;
}