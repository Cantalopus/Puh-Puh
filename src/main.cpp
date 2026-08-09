#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window{
        sf::VideoMode{{1000, 600}},
        "pong"
    };

    window.setFramerateLimit(120);

    sf::RectangleShape left_paddle{{20.0f, 120.0f}};
    left_paddle.setPosition({50.0f, 240.0f});

    sf::RectangleShape right_paddle{{20.0f, 120.0f}};
    right_paddle.setPosition({930.0f, 240.0f});

    sf::CircleShape ball{12.0f};
    ball.setOrigin({12.0f, 12.0f});
    ball.setPosition({500.0f, 300.0f});

    sf::Clock clock;

    constexpr float paddle_speed{500.0f};

////////////////////////////MAIN LOOP////////////////////////////////////////////////
    while(window.isOpen())
    {
        const float delta_time = clock.restart().asSeconds();

///////////LEFT PADDLE CONTROLS
        float left_movement{};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            left_movement -= paddle_speed * delta_time;
        }
        if (left_paddle.getPosition().y < 0.0f)
        {
            left_paddle.setPosition({
                left_paddle.getPosition().x,
                0.0f
            });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            left_movement += paddle_speed * delta_time;
        }
        if (left_paddle.getPosition().y > 480.0f)
        {
            left_paddle.setPosition({
                left_paddle.getPosition().x,
                480.0f
            });
        }
        left_paddle.move({0.0f, left_movement});

        

///////////RIGHT PADDLE CONTROLS
        float right_movement{};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            right_movement -= paddle_speed * delta_time;
        }
        if (right_paddle.getPosition().y < 0.0f)
        {
            right_paddle.setPosition({
                right_paddle.getPosition().x,
                0.0f
            });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            right_movement += paddle_speed * delta_time;
        }
        if (right_paddle.getPosition().y > 480.0f)
        {
            right_paddle.setPosition({
                right_paddle.getPosition().x,
                480.0f
            });
        }
        right_paddle.move({0.0f, right_movement});

////////////CLOSE WINDOW
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