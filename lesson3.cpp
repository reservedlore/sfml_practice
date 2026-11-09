#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;


void mouse_spawn(RenderWindow& window,float x2, float y2)
{
    static int counter_m = 0;
    if (counter_m > 4)
    {
        window.clear(Color(30, 30, 30));
        counter_m++;
    }
    static CircleShape mouse1(5.f);
    mouse1.setFillColor(Color::White);
    mouse1.setPosition({x2, y2});

    window.draw(mouse1);
}; 

int main()
{   
    bool is_run = true;

    RenderWindow window(VideoMode({500,600}), "67");
    
    while(window.isOpen())
    {
        while(const optional event = window.pollEvent())
        {
            if(event -> is <Event::Closed>())
            {
                window.close();
            }
        }

        Vector2i mousePos = Mouse::getPosition(window);
        int x = mousePos.x;
        int y = mousePos.y;
        
        cout << "x = " << x << " y = " << y << "\n";
        mouse_spawn(window, mousePos.x, mousePos.y);
        window.display();

        sleep(milliseconds(100));

        window.clear(Color(30,30,30));
        window.display();
    }

    return 0;
}
