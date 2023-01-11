#pragma once

#include "ProgressBar.h"

class HealthBar
{
public:
    HealthBar();
    HealthBar(int posX, int posY);
    ~HealthBar();
    
    void InitImg();
    void SetHealthBarPosition(int posX, int posY);
    void UpdateProgressBar(float pourcentage);
    void Draw(sf::RenderWindow& window) const;

private:

    ProgressBar *progressBar;
    UIImage* enemy_health_bar_background;
    UIImage* enemy_health_bar_foreground;
};

