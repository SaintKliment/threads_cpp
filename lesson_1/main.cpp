#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void work() {
    for(size_t i = 0; i < 10; i++){
        cout << "ID thread: " << this_thread::get_id() << "\t work \t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << "START THREAD" << endl; 
    
    thread th(work);
    thread th2(work);


    for(size_t i = 0; i < 10; i++){
        cout << "ID thread: " << this_thread::get_id() << "\t MAIN\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    th.join();
    th2.join();

    cout << "THE END THREAD" << endl;

    return 0;
}