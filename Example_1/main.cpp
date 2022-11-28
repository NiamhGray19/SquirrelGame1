/*
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
* About sprites and shapes https://www.sfml-dev.org/tutorials/2.5/graphics-sprite.php
* Set up your own VS2019 project https://www.youtube.com/watch?v=lFzpkvrscs4
* SFML and ImGui set up https://www.youtube.com/watch?v=2YS5WJTeKpI
*/

#include <iostream>  
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
// define render window size constants
#define winWidth 800
#define winHeight 600

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "My window");
        ImGui::SFML::Init(window);
    // Texture set up
    // sf::Texture tex_background;
    // tex_background.loadFromFile("winter_mountain_scene.jpg");

    // Sprite set up
    // sf::Sprite spr_background;
    // spr_background.setTexture(tex_background);

    sf::Texture tex_Dragon;
    tex_Dragon.loadFromFile("dragon.png");
    sf::IntRect rectSourceSprite(0, 0, 100, 100);
    sf::Sprite spr_dragon(tex_Dragon, rectSourceSprite);

    sf::Clock deltaClock;
    sf::Time elapsedTime;

    while (window.isOpen())
    {   
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (deltaClock.getElapsedTime().asSeconds() > 0.5f) {
            if (rectSourceSprite.left == 200)
                rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += 100;

            spr_dragon.setTextureRect(rectSourceSprite);
            deltaClock.restart();
        }

        // draw everything here...
        window.clear(sf::Color::Black);
        window.draw(spr_dragon);
        window.display();

    }

    return 0;
}

