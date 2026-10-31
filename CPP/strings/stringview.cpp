#include <iostream>
#include <string>
#include <string_view>
// To read string without copying string_view is here
int main()
{
    std::string_view s{"Hello world!"};
    // string_view don't convert to string but we can pass it by initialising string to string_view
    // Or we can use static_cast<std::string>
    using namespace std::string_view_literals;
    std::cout << "foo\n"sv;
    // Unlike std::string we can use constexpr
    constexpr std::string_view sv{"Hello, world!"};
    // Do not initialize std::string_view with a std::string literal it will be dropped
    std::string s { "Hello, world!" };
    std::string_view sv { s }; // sv is now viewing s

    s = "Hello, universe!";    // modifies s, which invalidates sv (s is still valid)
    std::cout << sv << '\n';   // undefined behavior

    sv = s;                    // revalidate sv: sv is now viewing s again
    std::cout << sv << '\n';   // prints "Hello, universe!"
	std::string_view str{ "Peach" };
	std::cout << str << '\n';

	// Remove 1 character from the left side of the view
	str.remove_prefix(1);
	std::cout << str << '\n';

	// Remove 2 characters from the right side of the view
	str.remove_suffix(2);
	std::cout << str << '\n';

	str = "Peach"; // reset the view
	std::cout << str << '\n';
    return 0;
}
