#include <SFML/Graphics.hpp>
#include <math.h>
const float SIZE = 1080;
const double PI = 3.14159265359;

void drawAstroid(float size, sf::RenderWindow &window) {
    float r = SIZE / 2;
    float offset = SIZE / 2;
    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[1].position = sf::Vector2f(offset, offset);
    lines[1].color = sf::Color::White;
    for (float a = 0; a <= 2*PI; a += 0.0001) {
        float cos3 = pow(cos(a),3);
        float sin3 = pow(sin(a),3);
        float x1 = r * cos3 + offset;
        float y1 = r * sin3 + offset;
        lines[0].position = sf::Vector2f(x1, y1);
        if (a < PI/2)lines[0].color  = sf::Color::Red;
        if (a > PI/2 and a < PI) lines[0].color  = sf::Color::Blue;
        if (a > PI and a < PI*3/2) lines[0].color  = sf::Color::Green;
        if (a > PI*3/2 and a < 2*PI) lines[0].color  = sf::Color::White;
        window.draw(lines);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "ASTROID!");

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
