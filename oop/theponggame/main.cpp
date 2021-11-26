#include <iostream>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
float const PI = 3.1456;
using namespace sf;

int main()
{
    float screenWidth = 1280, screenHeight = 720;
    float const handleSpeed = 350.f;
    float const ballSpeed = 200.f;
    float velocityVector;
    float angle = 45.f * PI / 180;

    Vector2f paddleSize{10, 200};

    ContextSettings settings;
    settings.antialiasingLevel = 5;
    CircleShape ball;
    RectangleShape leftHandle(paddleSize), rightHandle(paddleSize);

    ball.setFillColor(Color::White);
    ball.setRadius(10);
    ball.setOrigin(ball.getRadius(), ball.getRadius());
    ball.setPosition(screenWidth / 2, screenHeight / 2);

    leftHandle.setFillColor(Color::White);
    leftHandle.setPosition(0, (screenHeight - paddleSize.y) / 2);

    rightHandle.setFillColor(Color::White);
    rightHandle.setPosition(screenWidth - paddleSize.x, (screenHeight - paddleSize.y) / 2);

    Clock clock;
    RenderWindow window(VideoMode(screenWidth, screenHeight), "Pong!", Style::Default, settings);
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        velocityVector = dt * ballSpeed;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            if (rightHandle.getPosition().y > 0)
                rightHandle.move(0, -handleSpeed * dt);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            if (rightHandle.getPosition().y + paddleSize.y < screenHeight)
                rightHandle.move(0, handleSpeed * dt);
        }
        ball.move(sin(angle) * velocityVector, -cos(angle) * velocityVector);
        window.clear(Color::Black);
        window.draw(ball);
        window.draw(leftHandle);
        window.draw(rightHandle);
        window.display();
    }
}