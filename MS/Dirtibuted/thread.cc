#include <iostream>
#include <thread>

void hello() {
  std::cout << "\nHello, Beautiful World!\n";
  // std::cout << std::this_thread::get_id() << "\n";
}
int main() {
  std::thread t(hello);
  // t.detach(); -- fire and forget
  // std::thread t2 =
  //     std::move(t); // thread's ownership can be moved to another thread
  unsigned long const hd_conc = std::thread::hardware_concurrency();
  // hardware_concurrency(): This function returns an indication of the number
  // of threads that can truly run concurrently for a given execution of a
  // program
  // std::cout << hd_conc << std::endl;
  // std::cout << "Pthread Main: " << pthread_self()
  //           << "\t This Thread Main: " << std::this_thread::get_id()
  //           << "\n Hello: " << t.get_id() << "\n";
  t.join();
}