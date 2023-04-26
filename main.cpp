#include <SFML/Graphics.hpp>
#include <iostream>
#include "ComplexPlane.h"
using namespace std;
using namespace sf;

int main()
{
 
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Mandelbrot", Style::Default);
    sf::Event event;

    int aspect = VideoMode::getDesktopMode().height / VideoMode::getDesktopMode().width;
    cout << aspect;

    sf::Font font;										//title and directions
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    


    ComplexPlane object;
    while (window.isOpen())
    {
        window.display();



        while (window.pollEvent(event))
        {

            switch (event.type)
            {

            case sf::Event::Closed:					//exit event
                window.close();
                break;

            default:
                break;
            }
        }
    }
}
