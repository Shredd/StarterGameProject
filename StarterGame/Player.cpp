#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
    float x = 100.0f;
    float y = 100.0f;
    float vel = 2.0f;
    float speed = vel;
    int width = 30;
    int height = 30;

    void update(bool left, bool right, bool up, bool down){
        if(left || up){
            speed = -vel;
        } else if(right || down){
            speed = vel;
        }
    }

    void collide(sf::RectangleShape rect1, sf::RectangleShape rect2, int Type){
        if (rect1.getGlobalBounds().intersects(rect2.getGlobalBounds())) {
             if (Type == 1){
                std::cout << "Type 1" << std::endl;
             } else if (Type == 2){
                std::cout << "Type 2" << std::endl;
             }
        }
    }
};