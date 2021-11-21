#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main()
{
    std::string target;
    std::cout << "Dir: ", std::cin >> target;

    Texture img;
    Sprite sprite;
    img.loadFromFile(target);
    sprite.setTexture(img);

    RenderWindow window(VideoMode(500, 500), target);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }                          // Exit Event
        window.clear(Color::Cyan); // Clear screen and fill with color
        window.draw(sprite);
        window.display(); // Render
    }
}