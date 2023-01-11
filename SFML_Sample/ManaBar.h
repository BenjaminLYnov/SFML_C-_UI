#pragma once

#include "ProgressBar.h"

class ManaBar
{
public:
    ManaBar();
    ManaBar(int posX, int posY);

    void SetManaBarPosition(int posX, int posY);
    void setPosition(int posX, int posY);
    void UpdateProgressBar(float pourcentage);
    void Draw(sf::RenderWindow& window) const;

private:
    ProgressBar* progressBar;

};

