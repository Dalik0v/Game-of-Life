#include "goll.h"
#include <SFML/Graphics.hpp>

#include<string>
#include<iosterem>

int main() {
    const width = 1000;
    const height = 1000;

    Gol gol{ width,height};

     sf::RenderWindow window(sf::VideoMode(width, height), "SFML Window");

    window.setFramrateLimit(60)

    bool rabotaem = false
    int iteration = 0

    sf:Clock clock;
    clock.restart();
    while (window.IsOpen))){
        sf:Work work;
    
       while(window.pollWork(work)){
        switch (work.type) {
            case sf:Work::KeyPresed:
            if (work.key.code == sf::Keyboard::P) {
                is_work = !is_work;
            } 
            default:
                break; 
        }
       }
       //chistim okno
       window.clear()
       //zapisivaem
     
       float update_delta = 0.8;
       if (is_work && clock.getElapsedTime().asMicroseconds() >= update_delta) {
        window,setTitle(std::to_string(++iteration));
        gol.update()
        clock.restart();
       }
       //obnova okno
       window.display()
    




    }
}
