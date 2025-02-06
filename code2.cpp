#include<iostream>
#include<SFML/Graphics.hpp>
#include<random>
#include<ctime>
#include<cstdlib>

using namespace std;
using namespace sf;

class game
{
    private:
    RenderWindow window;

    Sprite spaceship;
    Sprite asteriod;
    Sprite background;
    CircleShape fire[1000];

    Texture spacestexture;
    Texture backgtexture; 
    Texture astertexture;

    int l;
    public:
    game(): window(VideoMode(1200,800),"Space Shooter"),l(-1)
    {
      spacestexture.loadFromFile("ship.PNG");
      spaceship.setTexture(spacestexture);
      spaceship.setScale(0.10,0.10);
      spaceship.setPosition(550,650);
    
      backgtexture.loadFromFile("1.jpg");
      background.setTexture(backgtexture);

      astertexture.loadFromFile("asteroid.PNG");
      asteriod.setTexture(astertexture);
      asteriod.setScale(0.15,0.15);

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
            asteriod_movement();
            shoot_fire();
            window.draw(background);
            window.draw(spaceship);
            window.draw(asteriod);
            for(int i=0;i<=l;i++)
            {
              window.draw(fire[i]);
            }
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

    void asteriod_movement()
    {
        asteriod.move(0,5);
        if(asteriod.getPosition().y>800)
        {
           int ran=rand()%1280;
           asteriod.setPosition(ran,10);
        }
        if(spaceship.getGlobalBounds().intersects(asteriod.getGlobalBounds()))
        {
            int ran=rand()%1280;
            asteriod.setPosition(ran,10);
        }
        for(int i=0;i<=l;i++)
        {
           if(fire[i].getGlobalBounds().intersects(asteriod.getGlobalBounds()))
        {
            int ran=rand()%1280;
            asteriod.setPosition(ran,10);
        }
        }
    }

    void shoot_fire()
    {
      if(Keyboard::isKeyPressed(Keyboard::Space))
      {
        l++;
        Vector2f current_pos=spaceship.getPosition();
        fire[l].setPosition(current_pos.x+33,current_pos.y);
        fire[l].setRadius(10);
        fire[l].setFillColor(Color::Red);
      }
      for(int i=0;i<=l;i++)
      {
        fire[i].move(0,-10);
      }
    }
};

int main()
{
    game g;
    g.run();
}