#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void draw_line(RenderWindow& window,float x1, float y1, float x2, float y2,float thickness, sf::Color color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float length = sqrt(dx*dx + dy * dy); //теорема Пифогора 

    RectangleShape line({length,thickness}); // создание прямоугольника длина,ширина
    line.setFillColor(color);

    line.setOrigin({0.f, thickness / 2.f}); // а это точка от которой начинаются координаты типо чтобы вращать от середины а не от левого верхнего угла
    line.setPosition({x1,y1}); // это тот самый левый верхний угол

    float radians1 = atan2(dy,dx); // ыыы радианы короче да
    line.setRotation(radians(radians1)); // это подсчёт угла через арктангенс

    window.draw(line);
}

int main()
{
    RenderWindow window(VideoMode({400,300}), "hz");
    
    while(window.isOpen())
    {
        while(const optional event = window.pollEvent())
        {
            if (event -> is <Event::Closed>())
            {
                window.close();
            }
        }
        
        window.clear(Color(00, 00, 00));

        draw_line(window, 30, 40, 60, 40, 10, Color::Red);
        draw_line(window, 45, 45, 45, 80, 10, Color::White);

        //лень писать функцию для #

        draw_line(window, 102, 100, 98,140, 5, Color::White);
        draw_line(window, 132, 100, 128,140, 5, Color::White);
        draw_line(window, 85, 110, 145, 110, 4, Color::White);
        draw_line(window, 85, 130, 145, 130, 4, Color::White);    
    

        window.display();

    }

    return 0;
}
