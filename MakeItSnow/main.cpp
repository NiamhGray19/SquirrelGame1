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
#define winWidth 798
#define winHeight 596

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "My window");
        ImGui::SFML::Init(window);
    // Texture set up
    sf::Texture tex_background;
    tex_background.loadFromFile("winter_mountain_scene.jpg");

    // Sprite set up
    sf::Sprite spr_background;
    spr_background.setTexture(tex_background);

    sf::Clock deltaClock;
    sf::Time elapsedTime;

    bool musicIsPlaying = true;
    bool startMusic = true;

    sf::Music music;
    if (!music.openFromFile("Music.wav"))
        return -1; // error
    music.play();

    while (window.isOpen())
    {
        if (!musicIsPlaying && startMusic)
        {
            musicIsPlaying = true;
            music.play();
        }
        if (musicIsPlaying && !startMusic)
        {
            musicIsPlaying = false;
            music.stop();
        }
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(spr_background);

        { // ImGui window
            ImGui::Begin("ImGui Window");
            ImGui::Text("Hello imgui World!");
            ImGui::Checkbox("Start Music", &startMusic);
            ImGui::End();
            ImGui::SFML::Render(window);
        }

        window.display();

    }

        ImGui::SFML::Shutdown();
    return 0;
}

