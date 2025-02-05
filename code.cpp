#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game
{
    private:
    RenderWindow window;
    Texture background;
    Sprite backg;
    Texture spaceship;
    Sprite spaces;
    Texture asteriod;
    Sprite aster;
    int x,y,move;
    public:
    Game(): window(VideoMode(800,800),"SPACE-SHOOTER"),x(650),y(320),move(10)
    {
       background.loadFromFile("1.jpg");
       backg.setTexture(background);
       spaceship.loadFromFile("ship.PNG");
       spaces.setTexture(spaceship);
       asteriod.loadFromFile("asteroid.PNG");
       aster.setTexture(asteriod);
       aster.setScale(0.10,0.10);
       spaces.setScale(0.15,0.15);
       spaces.setPosition(y,x);
    }
    void run()
    {
        Clock clock;
        Time timeSince=Time::Zero;
        Time TimePerFrame=seconds(1.f/60.f);
        while(window.isOpen())
        {
            timeSince+=clock.restart();
            while (timeSince>TimePerFrame)
            {
                timeSince-=TimePerFrame;
                window.clear(Color::White);
                window.draw(backg);
                spaceship_movement(timeSince);
                window.draw(spaces);
            }
            
            Event ef;
            while(window.pollEvent(ef))
            {
                if(ef.type==Event::Closed)
                {
                    window.close();
                }
            }
            window.draw(aster);
            window.display();
        }
    }
    void spaceship_movement(Time d)
    {
        Vector2f movement(0,0);
        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            movement.y-=move;
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            movement.y+=move;
        }
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
           movement.x-=move;
        }
        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            movement.x+=move;
        }
        if(x>650)x=650;
        if(y>680)y=680;
        if(x<0)x=0;
        if(y<0)y=0;
        spaces.move(movement);
    }
    void asteriod_falling()
    {

    }
};

int main()
{
    Game g;
    g.run();
}