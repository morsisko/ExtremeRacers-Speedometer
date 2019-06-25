#pragma once
#include <Windows.h>
#include <cmath>

struct Car
{
private:
	char _unknown[0x78];
	float speed;

public:
	int GetSpeed();
};