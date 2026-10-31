#include <SFML/Window.hpp>
#include <iostream>
int main()
{
    std::cout << "yes";
sf::Window window {};
sf::Event event;

// while there are pending events...
while (window.pollEvent(event))
{
    // check the type of the event...
    switch (event.type)
    {
        // Window closed
        case sf::Event::Closed:
            window.close();
            break;
        // Resized event
        case sf::Style::Resize:
            break;
        // Lost Focus and Gained Focus
        case sf::Event::LostFocus:
            break;
        case sf::Event::GainedFocus:
            break;
        // Text Entered envent not the same as Keypressed
        case sf::Event::TextEntered:
            if (event.text.unicode < 128) 
                std::cout << "ASCII char typed:" << static_cast<char>(event.text.unicode);
                // Keep in mind that some action such backspace will be capted to and need 
                // To be interpreted
        // Key pressend
        case sf::Event::KeyPressed:
            if (event.key.scancode == sf::Keyboard::Scan::Escape)
            {
                std::cout << "the escape key was pressed" << std::endl;
                std::cout << "scancode: " << event.key.scancode << std::endl;
                std::cout << "code: " << event.key.code << std::endl;
                std::cout << "control: " << event.key.control << std::endl;
                std::cout << "alt: " << event.key.alt << std::endl;
                std::cout << "shift: " << event.key.shift << std::endl;
                std::cout << "system: " << event.key.system << std::endl;
                std::cout << "description: " << sf::Keyboard::getDescription(event.key.scancode).toAnsiString() << std::endl;
                std::cout << "localize: " << sf::Keyboard::localize(event.key.scancode) << std::endl;
                std::cout << "delocalize: " << sf::Keyboard::delocalize(event.key.code) << std::endl;
            }
            break;
        case sf::Event::KeyReleased:
            break;
        // Mouse WheelMoved event is depreciated use MouseWheelScrolled instead
        case sf::Event::MouseWheelScrolled:
            if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                std::cout << "wheel type: vertical" << std::endl;
            else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
                std::cout << "wheel type: horizontal" << std::endl;
            else
                std::cout << "wheel type: unknown" << std::endl;
                std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
                std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
                std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
        case sf::Event::MouseButtonReleased:
            break;

        default:
            break;
        
        
    }
}
}
