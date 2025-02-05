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
    public:
    Game(): window(VideoMode(1280,720),"SPACE-SHOOTER")
    {
       background.loadFromFile("1.jpg");
       backg.setTexture(background);
       spaceship.loadFromFile("ship.PNG");
       spaces.setTexture(spaceship);
       spaces.setScale(0.15,0.15);
       spaces.setPosition(550,550);
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
            window.draw(spaces);
            window.display();
        }
    }
};

int main()
{
    Game g;
    g.run();
}