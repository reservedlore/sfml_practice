#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;
using namespace sf;

const int window_width = 800;
const int window_height = 600;
const float radius = 10.0f;
void draw_circle(RenderWindow& window, float x, float y, float r,Color color_l)
{
    CircleShape ball(r);
    ball.setFillColor(color_l);
    ball.setPosition({x,y});
    window.draw(ball);
};


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
    ball.setPosition({x1 - ball_r,y1 - ball_r});

    window.draw(line);
    window.draw(ball);
}

class Light
{
    //сделать конструктор и там делать святлячков в рандомных местах 
    // сделать анимацию через мерцания светлячка 60 фпс черзе glow != glow и в цикле сначало draw, потом move;
    int x;
    int y;
    int vx;
    int vy;
    bool glow;
    public:
        Light()
        {
            x = rand() % window_width;
            y = rand() % window_height;
            glow = true;

            vx = rand() % 11 - 5;
            vy = rand() % 11 - 5;
        }
    
        int get_x() const {return x;}
        int get_y() const {return y;}
        void turn_on() {glow = true;}
        void turn_off() { glow = false;}
    
        bool is_on() {return glow;}
    
        void move()
        {
            x += vx;
            y += vy;

            if (x + radius >= window_width or x <= 0)
                vx *= -1;

            if (y + radius >= window_height or y <= 0)
                vy *= -1;
        }

        void draw(RenderWindow& window)
        {
            if(glow)
                draw_circle(window,x,y,radius,Color::Yellow);
        }


};

int main()
{
    
    Color Brown(139,69,19);
    const int n = 10;
    Light obj[n];
    
    RenderWindow window(VideoMode({window_width,window_height}), " 67 ");
    window.setFramerateLimit(60);
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
       float wandX = mousePos.x; float wandY = mousePos.y;


        for (int i = 0; i < n; ++i)
            obj[i].draw(window);

        for (int i = 0; i < n; ++i)
            {
                obj[i].move();
                float dx = wandX - obj[i].get_x();
                float dy = wandY - obj[i].get_y();
                float dist = sqrt(dx*dx + dy*dy);
                if (dist < 15)
                    obj[i].turn_off();

            }
        mouse_spawn(window,mousePos.x,mousePos.y,mousePos.x + 40,mousePos.y + 40,5,5,Brown,Color::Green);


        window.display();        
    }
    return 0;
}
