#pragma once

#include <vector>
#include <Windows.h>
#include "Buffer.h"
#include "EnnemiGenerator.h"
#include "ProjectileVector.h"
#include "Assets.h"

#define BG_STARS 0
#define BG_WARP 1

#define LVL_START 0
#define LVL_GOING 1
#define LVL_WARPING 2
#define LVL_LOST 3

class LevelManager
{
private:
	EnnemiGenerator ennemis;
	ProjectileVector playerProjectile;
	ProjectileVector ennemiProjectile;
	PlayerObject player;
	float _boostTimer = 0.f;

	int _menuCursor = 0;
	int _menuNumber = 2;
	float _menuTimer = 0;
	bool _end = false;

	Assets &_assets;

	float levelTimer = 0;
	float enemyTimer = 0;
	int _levelState = 0;
	int CurrentSector = 1;
	float _levelSpeed = 1.f;
	int _levelBackground = 0;


public:
	LevelManager();
	LevelManager(Assets &assets) : _assets(assets) { Reset(); };
	~LevelManager();

	void Reset();

	bool Refresh(Buffer &buffer, float time);

	void Update(float time);
	void UpdateLevel(Buffer &buffer, float time);
	void UpdateBackground(Buffer &buffer, float time);
	void Draw(Buffer& buffer);
	void DrawBackground(Buffer &buffer);
	void DrawInterface(Buffer &buffer);
	
	void Event(float time);
	void MenuEvent(float time);

};

