#include <iostream>
#include <thread>
#include "Singleton.h"

void ThreadFoo() {
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->GetValue() << "\n";
}

void ThreadBar() {
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->GetValue() << "\n";
}

int main()
{
    std::cout << "If you see the same value, then singleton was reused (yay!)\n" <<
        "If you see different values, then 2 singletons were created!!\n\n" <<
        "RESULT:\n";
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    std::cin.get();

    return 0;
}
