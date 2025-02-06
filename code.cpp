#include<iostream>
#include<SFML/Graphics.hpp>
#include<random>
#include<ctime>
#include<cstdlib>
#include<thread>

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
    CircleShape fire[1000];
    int l;
    int x,y,move;
    public:
    Game(): window(VideoMode(800,800),"SPACE-SHOOTER"),x(650),y(320),move(10),l(-1)
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
                firemovement();
            }
            Vector2f checkbound=aster.getPosition();
            if(checkbound.y>790)
            {
                set_rand_aster();
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
            window.draw(spaces);
            for(int i=0;i<l;i++)
            {
              window.draw(fire[i]);
            }
            window.draw(aster);
            window.display();
        }
    }
    void spaceship_movement()
    {
        Vector2f movement(0,0);
        Vector2f movementfire(0,0);
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
        if(Keyboard::isKeyPressed(Keyboard::Q))
        {
           l++;
           fire[l].setRadius(15);
           fire[l].setFillColor(Color::Red);
           Vector2f shiploc=spaces.getPosition();
           fire[l].setPosition(shiploc.x+50,shiploc.y);
        }
        spaces.move(movement);
    }
    void set_aster()
    {
        Vector2f movement(0,0);
        movement.y+=12;
        aster.move(movement);
    }

    void set_rand_aster()
    {
        srand(time(nullptr));
        int ran=rand()%800;
        aster.setPosition(ran,10);
    }

    void firemovement()
    {
        for(int i=0;i<l;i++)
        {
           Vector2f movementfire(0,0);
           movementfire.y-=15;
          fire[i].move(movementfire);
        } 
    }
    // void in_range()
    // {
    //   Vector2f current=spaces.getPosition();
    //   if(current.y>650)
    //   {
    //     y=650;
    //   }
    //   if(current.x>680)
    //   {
    //     x=680;
    //   };
    //   if(current.y<0)
    //   {
    //     y=0;
    //   }
    //   if(current.x<0)
    //   {
    //     x=0;
    //   }
    //   spaces.setPosition(x,y);
    // }
};

int main()
{
    Game g;
    g.run();
}