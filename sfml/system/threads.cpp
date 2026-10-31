#include <SFML/System.hpp>
#include <SFML/System/Thread.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>

// they are many tools to protect code in threads one primitive is mutex that protects
// a function to be used in another thread "MUtual EXclusion"

sf::Mutex mutex;

void func()
{
  // this function is started when thread.launch() is called
  mutex.lock(); // locking the function
  for (int i = 0; i < 10; ++i)
    std::cout << "I'm thread number one" << std::endl;
  mutex.unlock();
}

// mutex is not exection an return proofed so consider wrapping it is sf::lock to auto unlock

bool func3()
{
    sf::Lock lock(mutex); // mutex.lock()

    if (!image1.loadFromFile("..."))
        return false; // mutex.unlock()

    if (!image2.loadFromFile("..."))
        return false; // mutex.unlock()

    if (!image3.loadFromFile("..."))
        return false; // mutex.unlock()

    return true;
} // mutex.unlock()
void func2(int x)
{
  // The only way to pause a thread is to change its launching function
  sf::sleep(sf::milliseconds(10));
}
int main()
{
  // create a thread with func() as entry point
  sf::Thread thread(&func);
  // run it
  thread.launch();

  // the main thread continues to run...
  
  for (int i = 0; i < 10; ++i)
    std::cout << "I'm the main thread" << std::endl;
  
  sf::Thread thread2(&func2, 5); // It can use argument and member functions
  // sf::Thread doesn't have a constructor so if I put it in a class I should init list it
  thread2.launch();
  thread.wait(); // block thread exec until thread1 is finished
  return 0;
}


