#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1280,720}),"67");
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    
    window.clear(sf::Color(30, 30, 50));

   sf::CircleShape ball(20.f);
   ball.setFillColor(sf::Color::Yellow);
   ball.setOutlineColor(sf::Color::Black);
   ball.setOutlineThickness(2.f);

   ball.setPosition({200.f,150.f}); 

    window.display();

    }
}
