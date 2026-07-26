#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window{
        sf::VideoMode{{1000, 600}},
        "pong"
    };

    window.setFramerateLimit(60);

    sf::RectangleShape left_paddle{{20.0f, 120.0f}};
    left_paddle.setPosition({50.0f, 240.0f});

    sf::RectangleShape right_paddle{{20.0f, 120.0f}};
    right_paddle.setPosition({930.0f, 240.0f});

    sf::CircleShape ball{12.0f};
    ball.setOrigin({12.0f, 12.0f});
    ball.setPosition({500.0f, 300.0f});

    while(window.isOpen())
    {

        while (const auto event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();

        window.draw(left_paddle);
        window.draw(right_paddle);
        window.draw(ball);

        window.display(); 
    }
}