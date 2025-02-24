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

    Font font;
    Text string;

    int l;
    int score;
    public:
    game(): window(VideoMode(1200,800),"Space Shooter"),l(-1),score(0)
    {
      spacestexture.loadFromFile("ship.PNG");
      spaceship.setTexture(spacestexture);
      spaceship.setScale(0.10,0.10);
      spaceship.setPosition(550,650);
    
      backgtexture.loadFromFile("1.jpg");
      background.setTexture(backgtexture);

      astertexture.loadFromFile("asteroid.PNG");
      asteriod.setTexture(astertexture);
      asteriod.setScale(0.08,0.08);

      font.loadFromFile("Arial.ttf");
      string.setFont(font);
      string.setFillColor(Color::White);
      string.setCharacterSize(40);
      string.setPosition(30, 0);
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
                if(ef.type==Event::KeyPressed)
                {
                    if(ef.key.code==Keyboard::Space)
                    {
                      shoot_fire();
                    }
                }
            }
            window.clear(Color::White);
            spaceship_movement();
            asteriod_movement();
            fire_movement();
            string.setString("Score : " + to_string(score));
            window.draw(background);
            window.draw(spaceship);
            window.draw(asteriod);
            window.draw(string);
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
           int ran=rand()%1180;
           asteriod.setPosition(ran,10);
        }
        if(spaceship.getGlobalBounds().intersects(asteriod.getGlobalBounds()))
        {
            int ran=rand()%1180;
            asteriod.setPosition(ran,10);
            score--;
        }
        for(int i=0;i<=l;i++)
        {
           if(fire[i].getGlobalBounds().intersects(asteriod.getGlobalBounds()))
        {
            int ran=rand()%1180;
            asteriod.setPosition(ran,10);
            score++;
        }
        }
    }

    void shoot_fire()
    {
      if(1)
      {
        l++;
        Vector2f current_pos=spaceship.getPosition();
        fire[l].setPosition(current_pos.x+33,current_pos.y);
        fire[l].setRadius(10);
        fire[l].setFillColor(Color::Red);
      }
    }

    void fire_movement()
    {
        for(int i=0;i<=l;i++)
      {
        if(fire[i].getPosition().y<1200)
        fire[i].move(0,-10);
        else
        {
            for (int j = i;j < l;j++)
            {
                fire[j] = fire[j + 1];
            }
            l--;
        }
        
      }
    }
};

int main()
{
    game g;
    g.run();
}