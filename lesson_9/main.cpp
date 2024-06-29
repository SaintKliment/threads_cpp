#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

recursive_mutex rm;
mutex m;

void  Foo(int a) { 
    cout << a << "   ";
    
    rm.lock();

    this_thread::sleep_for(chrono::milliseconds(300));

    if (a<=1) {
        cout << endl;
        rm.unlock();
        return;
    }

    a--;

    Foo(a);
    rm.unlock();
}

int main() {
    setlocale(LC_ALL, "Russian");

    thread t1(Foo, 10);
    thread t2(Foo, 10);
    
    t1.join();
    t2.join();

    // m.lock(); // нельзя открыть больше одного раза
    // m.unlock();

    // rm.lock();
    // rm.lock();
    // rm.lock();

    // rm.unlock();
    // rm.unlock();
    // rm.unlock();

    return 0;
}