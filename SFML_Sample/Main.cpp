#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameData.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    GameData g_GameData;
    g_GameData.Init();

    sf::Clock timer;

    float deltaTime = 0;
    float dtLogic = 15;
    float updateTime = 0;

    while (window.isOpen())
    {
        // Delta Time
        deltaTime = timer.getElapsedTime().asMilliseconds();
        updateTime += deltaTime;
        timer.restart();

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();

        g_GameData.Update();

        g_GameData.Draw(window);

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}