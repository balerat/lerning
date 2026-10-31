#include <SFML/System.hpp>
#include <iostream>
int main()
{
// A sf::Time value can be constructed from a lot of source
sf::Time t1 = sf::microseconds(10000);
sf::Time t2 = sf::milliseconds(10);
sf::Time t3 = sf::seconds(0.01f);

// It can be converted back
sf::Int64 usec = t1.asMicroseconds();
sf::Int32 msec = t2.asMilliseconds();
float     sec  = t3.asMilliseconds();

// It supports arithmetic operators
sf::Time t4 = t1 + t2;
sf::Time t5 = t1 * 2.0f;
bool b1 = (t1 == t2);
bool b2 = (t3 > t4);

// Mesuring time elapsed
sf::Clock myclock; // starts the clock
sf::Time elapsed1 = myclock.getElapsedTime();
std::cout << elapsed1.asSeconds() << std::endl;
myclock.restart(); // restarts the clock
  // It also return the elapsed time to avoid the gap when calling it before
return 0;
}

