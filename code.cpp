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
    public:
    Game(): window(VideoMode(800,800),"SPACE-SHOOTER")
    {
       background.loadFromFile("1.jpg");
       Sprite backg(background);
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
            window.display();
        }
    }
};

int main()
{
    Game g;
    g.run();
}