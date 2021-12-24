// #include <pthread.h>

#include <iostream>
#include <thread>

using namespace std; 

int main()
{
    static int counter = 0;
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    // only allow one thread to increment at a time
    pthread_mutex_lock(&mutex);

    ++counter;

    // store value before any other threads increment it further
    int result = counter;

    pthread_mutex_unlock(&mutex);

    std::cout << counter << std::endl;

    return result;
}