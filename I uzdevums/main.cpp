#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
using namespace std;

const float SIZE = 600;
const double PI = 3.14159265359;

void drawAstroid(float size, sf::RenderWindow &window) {
    float r = SIZE / 2;
    float offset = SIZE / 2;
    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[1].position = sf::Vector2f(offset, offset);
    lines[1].color = sf::Color::White;
    for (float a = 0; a <= 2*PI; a += 0.0001) {
        float x1 = r * cos(a) + offset;
        float y1 = r * sin(a) + offset;
        lines[0].position = sf::Vector2f(x1, y1);
        lines[0].color  = sf::Color::Red;
        window.draw(lines);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "ASTROID!");
    //sf::CircleShape shape(SIZE/2.f);
    //shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawAstroid(SIZE, window);
        window.display();
    }

    return 0;
}
