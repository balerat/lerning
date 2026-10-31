#include <iostream>

class Simple
{
private:
  int m_id{};

public:
  Simple(int id) : m_id{id} 
  {
  }

  int getID() const { return m_id; }
  void setID(int id) { m_id = id; }

  void print() { std::cout << m_id; } // cpp knows that we are talking about m_id of simple class because it uses this pointer
  // void print() { std::cout << this->m_id }
  // Remember -> is to select a member from a pointer it is the same as doing (*ptr).member

  // Method chaining: returning *this in member function so that we can use multiple member functions in a row on a single object

  // How to reset a object : do not call the constructor again use this vvvvv
  // Prefer to put your class definitions in a header file with the same name as the class. 
  // Trivial member functions (such as access functions, constructors with empty bodies, etc…) can be defined inside the class definition.
  // Prefer to define non-trivial member functions in a source file with the same name as the class.
  void reset() { *this = {2}; }


};

int main()
{
  Simple simple{1};
  simple.setID(2);

  simple.print();

  return 0;
}