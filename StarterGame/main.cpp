#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.cpp"
#include "Object.cpp"

using namespace std;

string Title = "Template Game";
int WINDOW_WIDTH = 1000;
int WINDOW_HEIGHT = 800;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), Title, sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    //Test Object class and object declared
    Object obj1;
    sf::RectangleShape Objtest(sf::Vector2f(obj1.x, obj1.y));
    Objtest.setSize(sf::Vector2f(obj1.width, obj1.height));
    Objtest.setFillColor(sf::Color::Blue);
    Objtest.setPosition(obj1.x, obj1.y);

    //player class and object declared
    Player playerobj;
    sf::RectangleShape player(sf::Vector2f(playerobj.x, playerobj.y));
    player.setSize(sf::Vector2f(playerobj.width, playerobj.height));
    player.setFillColor(sf::Color::Red);
    player.setPosition(500.0f, 300.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            playerobj.update(true, false, false, false);
            player.move(sf::Vector2f(playerobj.speed, 0.0f));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            playerobj.update(false, true, false, false);
            player.move(sf::Vector2f(playerobj.speed, 0.0f));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            playerobj.update(false, false, true, false);
            player.move(sf::Vector2f(0.0f, playerobj.speed));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            playerobj.update(false, false, false, true);
            player.move(sf::Vector2f(0.0f, playerobj.speed));
        }

        //checks the bounds of the player object compared to the Objtest object global bounds
        playerobj.collide(player, Objtest, 2);
        
        window.clear();
        window.draw(player);
        window.draw(Objtest);
        window.display();
    }
    return 0;
}