#include <SFML/Window.hpp>

// Oppening a window
int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My Window");
    // Video mode defines the size of the window second arg is title of the window
    // Third arg is the style of the window (decoration buttons)

    // If we want to create the windows after the construction
    sf::Window window2;
    window2.create(sf::VideoMode(800, 600), "My window2");
    window.setPosition(sf::Vector2(10, 50));
    sf::Vector2 size = window.getSize();
    unsigned int with = size.x;
    unsigned int height = size.y;

    // We can use other libraries to create windows decoration by changing the constructor
    // In sf::WindowHandle and then calling sf::Window window(handle);

    // How to allow Vertical synchronization to prevent tearing:
    window.setVerticalSyncEnabled(true);

    // If you want to set the framerate you can change:
    // window.setFramerateLimit(60);
    // This one can be pretty unreliable and do not use it at the same time as VSync

    // check wether the window has the focus
    bool focus = window.hasFocus();
    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) // pollEvent returns true if events pending false while not
        {
            // "Close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}

// You can create multiple windows in a single or multiple threads
// Multiple monitors are not correctly supported yet
// Event loop must be called in the same thread that create the window
// You can move the rest (rendering, physics, logic, ...) in another thread
