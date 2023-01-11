#pragma once

#include <vector>
#include <SFML/System/Clock.hpp>
#include "HealthBar.h"
#include "UIText.h"
#include "ManaBar.h"


struct GameEvent
{
    bool triggered = false;
    int player = 0;
    int scoreDelta = 0;
    int healthDelta = 0;
    int manaDelta = 0;
    float time = 0;

    void PrintEvent();
};

class PlayerInfos
{
public:

    float fHealth = 0;
    float fMana = 0;
    float fScore = 0;
    const float fMaxHealth = 100;
    const float fMaxMana = 100;

    int playerID = -1;

    void ApplyEvent(const GameEvent& _event);
    void PrintData();
};
class GameData
{
public:

    ~GameData();

    void Init();

    void InitHealthBar();

    void Update();

    void DrawHealthBars(sf::RenderWindow& window) const;
    void Draw(sf::RenderWindow& window) const;

    static const int nbPlayers = 2;
    PlayerInfos players[nbPlayers];

private:

    sf::Clock m_clock;
    float m_timeEvents = 0;
    std::vector<GameEvent> m_vEvents;

    HealthBar* playersHealthBar;
    ManaBar* PlayersManaBar;

    UIText* playersText;
};

