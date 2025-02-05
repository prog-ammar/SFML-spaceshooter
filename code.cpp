#include<iostream>
#include<SFML/Graphics.hpp>
#include<random>
#include<ctime>
#include<cstdlib>

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
        window.setFramerateLimit(60);
        Clock clock;
        Time timeSince=Time::Zero;
        Time TimePerFrame=seconds(1.f/60.f);
        while(window.isOpen())
        {
            timeSince+=clock.restart();
            while (timeSince>TimePerFrame)
            {
                timeSince-=TimePerFrame;
                set_aster();
                spaceship_movement();
            }
            if(1)
            {
                Vector2f ss=aster.getPosition();
                if(ss.y>700)
                {
                    set_rand_aster();
                }
            }
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
            //in_range();
            window.draw(spaces);
            window.draw(aster);
            window.display();
        }
    }
    void spaceship_movement()
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
        spaces.move(movement);
    }
    void set_aster()
    {
        Vector2f movement(0,0);
        movement.y+=10;
        aster.move(movement);
    }

    void set_rand_aster()
    {
        srand(time(nullptr));
        int ran=rand()%800;
        aster.setPosition(ran,10);
    }
    // void in_range()
    // {
    //   if(x>650)
    //   {
    //     x=650;
    //     spaces.setPosition(y,x);
    //   }
    //   if(y>680)
    //   {
    //     y=680;
    //     spaces.setPosition(y,x);
    //   };
    //   if(x<0)
    //   {
    //     x=0;
    //     spaces.setPosition(y,x);
    //   }
    //   if(y<0)
    //   {
    //     y=0;
    //     spaces.setPosition(y,x);
    //   }
      
    // }
};

int main()
{
    Game g;
    g.run();
}