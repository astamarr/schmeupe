// Jeu.cpp�: d�finit le point d'entr�e pour l'application console.
//


#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <random>
#include "Assets.h"
#include "Ressource.h"
#include "Buffer.h"
#include "Objet.h"
#include "PlayerObject.h"
#include "Projectile.h"
#include "ObjectVector.h"
#include "NYtimer.h";
using namespace std;


int main()
{
	Buffer a;
	NYTimer timer;
	timer.start();
	PlayerObject o;
	ObjectVector enemies;
	float time;
	float shootTimer = 0;
	ObjectVector projectile;
	srand(25);

	
	Assets   testAssets;
	Assets   testAssets2;
	testAssets.LoadPlayerFromFile("ship.txt");
	testAssets2.LoadPlayerFromFile("ship2.txt");

	a.InitStars();



	while (true) {

		time = timer.getElapsedSeconds(true);
		shootTimer += time;
		a.Reset(0x00);
		
		a.DrawStars();
		//a.Update(o.GetY(), o.GetX(), 'O', 0x00);
		projectile.Draw(a);
		a.UpdateWithBuffer(o.GetY(), o.GetX(), testAssets.GetAsset("player"));
		enemies.Draw(a);

		if (GetAsyncKeyState('Q'))
			o.Move(-1, 0, time);
		if (GetAsyncKeyState('D'))
			o.Move(1, 0, time);
		if (GetAsyncKeyState('S'))
			o.Move(0,1, time);
		if (GetAsyncKeyState('Z'))
			o.Move(0,-1, time);
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
		if (GetAsyncKeyState(VK_SPACE) && shootTimer > .05f) {
			o.Shoot(projectile);
		}
		o.Update(time);
		enemies.Update(time);
		projectile.UpdateWithBoundCheck(time);

		a.MoveStars(-120.f, 0, time);

#ifdef _DEBUG
		//timer.start();
#endif
		a.Draw();
		
	}

}

