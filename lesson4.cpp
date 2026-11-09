#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void mouse_spawn(RenderWindow& window,float x1, float y1, float x2, float y2,float thickness,float ball_r, sf::Color color_l,Color color_b = Color::Yellow)
{
    // палка
    float dx = x2 - x1;
    float dy = y2 - y1;
    float length = sqrt(dx*dx + dy * dy); //теорема Пифогора 

    RectangleShape line({length,thickness}); // создание прямоугольника длина,ширина
    line.setFillColor(color_l);

    line.setOrigin({0.f, thickness / 2.f}); // а это точка от которой начинаются координаты типо чтобы вращать от середины а не от левого верхнего угла
    line.setPosition({x1,y1}); // это тот самый левый верхний угол

    float radians1 = atan2(dy,dx); // ыыы радианы короче да
    line.setRotation(radians(radians1)); // это подсчёт угла через арктангенс

    //кружок
    CircleShape ball(ball_r);
    ball.setFillColor(color_b);
    ball.setPosition({x1 - 10,y1 - 10});

    window.draw(ball);
    window.draw(line);
}



int main()
{
    Color Brown(139,69,19);
    RenderWindow window(VideoMode({700,550}), " 67 ");
    window.setMouseCursorVisible(false);

    while(window.isOpen())
    {
        while(const optional event = window.pollEvent())
        {
            if(event -> is <Event::Closed>())
            {
                window.close();
            }
        }


        window.clear(Color(30,30,30));

        Vector2i mousePos = Mouse::getPosition(window);
        int x = mousePos.x;
        int y = mousePos.y;
        
        mouse_spawn(window,mousePos.x,mousePos.y,mousePos.x + 40,mousePos.y + 40,5,5,Brown);
        window.display();
        
        sleep(milliseconds(20));
        window.clear(Color(30,30,30));
        window.display();
       
        
    }
    return 0;
}
