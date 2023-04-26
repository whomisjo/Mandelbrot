#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int main()
{
    VideoMode::getDesktopMode().width;
    VideoMode::getDesktopMode().height;

    int aspect = VideoMode::getDesktopMode().height / VideoMode::getDesktopMode().width;
        cout << aspect;


    
}
