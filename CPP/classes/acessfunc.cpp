// An access function is a trivial public member function whose job is to retrieve or change the value
// of a private member variable

class Date
{
private:
  int m_year { 2020 };
  int m_mounth { 10 };
  int m_day { 14 };

public:
  int getYear() const { return m_year; }    // getter for year
  void setYear(int year) { m_year = year; } // setter for year
};

// One reason to use m_ is to avoid having getter and variable with the same name (class doesn't support it)
// Getters should return by value or by const lvalue reference
// It is okay to return a const lvalue reference to a data member. 
// A member function returning a reference should return a reference of the same type as the data member being returned to avoid unnecessary conversions
// A usefull way is to use auto for the getter

// An rvlaue object is destroyed at the end of the full expression in which it is created. Any references to members of the rvalue object are left dangling at that point
// A reference to a member of an rvalue object can be safely used within the full expression where the rvalue object is created.
// Prefer to use return value of a member function that returns by references immediately, to avoid issues wih dangling reference when the implicit object is an rvalue
// Do not save a returned ref to use later
// Do not return non_const references to private data members (it can change them on public domaine)


// Prefer implementing functions as non-members when possible (especially functions that contain application specific data or logic)
// Decalre public members first, protected next, and private members last. This spotlights the public interface and demphasizes the implementation details
