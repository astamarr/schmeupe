#include "Objet.h"

void Objet::Move(const float x, const float y, const int time) {
	_xSpeed += (x*time)/1000.f;
	_ySpeed += (y*time) / 1000.f;
	if (_xSpeed > _maxSpeed) _xSpeed = _maxSpeed;
	if (_xSpeed < -_maxSpeed) _xSpeed = -_maxSpeed;
	if (_ySpeed > _maxSpeed) _ySpeed = _maxSpeed;
	if (_ySpeed < -_maxSpeed)_ySpeed = -_maxSpeed;
};

void Objet::Update(const int time) {
	float movex = (_xSpeed*time)/1000.f;
	float movey = (_ySpeed*time)/1000.f;
	_deltaX += movex;
	_deltaY += movey;
	_x += (int)_deltaX;
	_y += (int)_deltaY;
	_deltaX -= (int)_deltaX;
	_deltaY -= (int)_deltaY;
	_xSpeed = (1/(1+(time/1000.f)))*_xSpeed;
	_ySpeed = 0.7*_ySpeed;
}

