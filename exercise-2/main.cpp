#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

using namespace std;

#define NUM_THREADS 5

struct Counter
{
    int value;

    Counter() : value(0) {}

    void increment()
    {
        ++value;
    }
};

std::mutex m;
int i = 0;

int main()
{
    Counter counter;

    std::vector<std::thread> threads;
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        threads.push_back(std::thread([&counter]()
                                      {m.lock();
                                          for (int i = 0; i < 10000; ++i)
                                          {
                                              counter.increment();
                                          } m.unlock(); }));
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    cout << "counter.value = " << counter.value << endl;
    return 0;
}
