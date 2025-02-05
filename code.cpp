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
    int x,y,move;
    public:
    Game(): window(VideoMode(800,800),"SPACE-SHOOTER"),x(650),y(320),move(10)
    {
       background.loadFromFile("1.jpg");
       backg.setTexture(background);
       spaceship.loadFromFile("ship.PNG");
       spaces.setTexture(spaceship);
       spaces.setScale(0.15,0.15);
       spaces.setPosition(y,x);
    }
    void run()
    {
        while(window.isOpen())
        {
            Event ef;
            while(window.pollEvent(ef))
            {
                if(ef.type==Event::Closed)
                {
                    window.close();
                }
            }
            window.clear(Color::White);
            window.draw(backg);
            spaceship_movement();
            window.draw(spaces);
            window.display();
        }
    }
    void spaceship_movement()
    {
        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            x=x-move;
            spaces.setPosition(y,x);
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            x=x+move;
            spaces.setPosition(y,x);
        }
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
           y=y-move;
           spaces.setPosition(y,x);
        }
        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            y=y+move;
           spaces.setPosition(y,x);
        }
        if(x>650)x=650;
        if(y>680)y=680;
        if(x<0)x=0;
        if(y<0)y=0;
        spaces.setPosition(y,x);
    }
};

int main()
{
    Game g;
    g.run();
}