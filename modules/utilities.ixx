module;

#include <SFML/Window/VideoMode.hpp>
#include <fmt/format.h>
#include <SFML/Graphics.hpp>

export module utilities; // Name doesn't have to match the .ixx file

export void puh_puh(){

    sf::RenderWindow window{
        sf::VideoMode{{1000, 600}},
        "pong"
    };

    const sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    const sf::Vector2u window_size = window.getSize();

    window.setPosition({100, 100});
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

    float ball_velocity_x{350.0f};
    float ball_velocity_y{250.0f};
    constexpr float ball_radius{12.0f};

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
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            left_movement += paddle_speed * delta_time;
        }

        left_paddle.move({0.0f, left_movement});

        if (left_paddle.getPosition().y < 0.0f)
        {
            left_paddle.setPosition({
                left_paddle.getPosition().x,
                0.0f
            });
        }
        if (left_paddle.getPosition().y > 480.0f)
        {
            left_paddle.setPosition({
                left_paddle.getPosition().x,
                480.0f
            });
        }
        

        

///////////RIGHT PADDLE CONTROLS
        float right_movement{};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            right_movement -= paddle_speed * delta_time;
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            right_movement += paddle_speed * delta_time;
        }

        right_paddle.move({0.0f, right_movement});

        if (right_paddle.getPosition().y < 0.0f)
        {
            right_paddle.setPosition({
                right_paddle.getPosition().x,
                0.0f
            });
        }
        if (right_paddle.getPosition().y > 480.0f)
        {
            right_paddle.setPosition({
                right_paddle.getPosition().x,
                480.0f
            });
        }
        
////////////BALL MOVEMENT

        ball.move({
            ball_velocity_x * delta_time,
            ball_velocity_y * delta_time
        }); 

        if (ball.getPosition().y - ball_radius < 0.0f)
            ball_velocity_y = -ball_velocity_y;
        if (ball.getPosition().y + ball_radius > 600.0f)
            ball_velocity_y = -ball_velocity_y;
/*
        if (ball.getPosition().y > right_paddle.getPosition().y 
            && ball.getPosition().y < right_paddle.getPosition().y + 120.0f 
                && ball.getPosition().x >= right_paddle.getPosition().x){
            ball_velocity_x = -ball_velocity_x;
        }
        if (ball.getPosition().y > left_paddle.getPosition().y 
            && ball.getPosition().y < left_paddle.getPosition().y + 120.0f 
                && ball.getPosition().x <= left_paddle.getPosition().x + left_paddle.getSize().x){
            ball_velocity_x = -ball_velocity_x;
        }
*/        

        // Right paddle
        if (ball_velocity_x > 0.0f
            && ball.getPosition().x + ball_radius >= right_paddle.getPosition().x
            && ball.getPosition().x - ball_radius
                <= right_paddle.getPosition().x + right_paddle.getSize().x
            && ball.getPosition().y + ball_radius >= right_paddle.getPosition().y
            && ball.getPosition().y - ball_radius
                <= right_paddle.getPosition().y + right_paddle.getSize().y)
        {
            ball_velocity_x = -ball_velocity_x;
        }
        
        // Left paddle
        if (ball_velocity_x < 0.0f
            && ball.getPosition().x - ball_radius
                <= left_paddle.getPosition().x + left_paddle.getSize().x
            && ball.getPosition().x + ball_radius >= left_paddle.getPosition().x
            && ball.getPosition().y + ball_radius >= left_paddle.getPosition().y
            && ball.getPosition().y - ball_radius
                <= left_paddle.getPosition().y + left_paddle.getSize().y)
        {
            ball_velocity_x = -ball_velocity_x;
        }

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