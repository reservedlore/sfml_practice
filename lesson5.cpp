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
    const int n = 10;
    Light obj[n];
    
    RenderWindow window(VideoMode({window_width,window_height}), " 67 ");
    window.setFramerateLimit(60);
    
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

        for (int i = 0; i < n; ++i)
            obj[i].draw(window);

        for (int i = 0; i < n; ++i)
            obj[i].move();
       

        window.display();        
    }
    return 0;
}
