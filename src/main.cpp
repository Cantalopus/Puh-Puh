#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(800, 600),
        "Moving Circle"
    );

    window.setFramerateLimit(60);

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(350.f, 250.f);

    constexpr float speed{7.f};

    while (window.isOpen())
    {

        sf::Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            circle.move(-speed, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            circle.move(speed, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            circle.move(0.f, -speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            circle.move(0.f, speed);
        }
        
        window.clear(sf::Color(30,30,60));
        window.draw(circle);
        window.display();
    }
}