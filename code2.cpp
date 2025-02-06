#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class game
{
    private:
    RenderWindow window;

    Sprite spaceship;
    Sprite asteriod;
    Sprite background;

    Texture spacestexture;
    Texture backgtexture; 
    Texture astertexture;

    public:
    game(): window(VideoMode(1200,800),"Space Shooter")
    {
      spacestexture.loadFromFile("ship.PNG");
      spaceship.setTexture(spacestexture);
      spaceship.setScale(0.10,0.10);
      spaceship.setPosition(550,650);
    
      backgtexture.loadFromFile("1.jpg");
      background.setTexture(backgtexture);

      astertexture.loadFromFile("asteriod.PNG");
      asteriod.setTexture(astertexture);
      asteriod.setScale(0.10,0.10);

      window.setFramerateLimit(60);
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
            spaceship_movement();
            window.draw(background);
            window.draw(spaceship);
            window.display();
       }
    }

    void spaceship_movement()
    {
       Vector2f movement(0,0);
       if(Keyboard::isKeyPressed(Keyboard::W))
        {
            movement.y-=10;
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            movement.y+=10;
        }
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
           movement.x-=10;
        }
        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            movement.x+=10;
        }
        spaceship.move(movement);
        
        Vector2f current_pos=spaceship.getPosition();
        if(current_pos.x>1120)
        {
            current_pos.x=1120;
        }
        if(current_pos.x<0)
        {
            current_pos.x=0;
        }
        if(current_pos.y>720)
        {
            current_pos.y=720;
        }
        if(current_pos.y<0)
        {
            current_pos.y=0;
        }
        spaceship.setPosition(current_pos);
    }
};

int main()
{
    game g;
    g.run();
}