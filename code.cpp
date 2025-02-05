#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game
{
    private:
    RenderWindow window;
    public:
    Game(): window(VideoMode(800,800),"SPACE-SHOOTER")
    {}
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
            window.display();
        }
    }
}