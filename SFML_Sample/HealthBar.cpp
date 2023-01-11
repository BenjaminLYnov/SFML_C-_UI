#include "HealthBar.h"
#include <iostream>

HealthBar::HealthBar()
{
    InitImg();
    SetHealthBarPosition(0, 0);
}

HealthBar::HealthBar(int posX, int posY)
{
    InitImg();
    SetHealthBarPosition(posX, posY);
}


HealthBar::~HealthBar()
{
    delete progressBar;
    delete enemy_health_bar_background;
    delete enemy_health_bar_foreground;
}

void HealthBar::InitImg()
{
    progressBar = new ProgressBar();
    enemy_health_bar_background = new UIImage("Resources/Images/enemy_health_bar_background_000.png", 0, 0, 256, 64);
    enemy_health_bar_foreground = new UIImage("Resources/Images/enemy_health_bar_foreground_000.png", 0, 0, 256, 64);

    progressBar->setColor(sf::Color(0, 255, 0)); // Green
}

void HealthBar::SetHealthBarPosition(int posX, int posY)
{
    progressBar->getBar()->setPosition(posX, posY);
    enemy_health_bar_background->setPosition(posX, posY);
    enemy_health_bar_foreground->setPosition(posX, posY);
}

void HealthBar::UpdateProgressBar(float pourcentage)
{
    progressBar->setProgressBarPourcentage(pourcentage);

    if (pourcentage <= 30)
    {
        progressBar->setColor(sf::Color(255, 0, 0)); // Red
    }
    else if (pourcentage <= 60)
    {
        progressBar->setColor(sf::Color(255, 128, 0));  // Orange
    }
    else {
        progressBar->setColor(sf::Color(0, 255, 0)); // Green
    }
}

void HealthBar::Draw(sf::RenderWindow& window) const
{
    enemy_health_bar_foreground->Draw(window);
    enemy_health_bar_background->Draw(window);
    progressBar->getBar()->Draw(window);
}
