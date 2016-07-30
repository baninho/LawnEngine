#pragma once
#include <stdio.h>

extern float IntakePressure;
extern float EngineSpeed;
extern float AirMassFlow, AirMassPerCyl;

class AirSystem
{
public:
	AirSystem();
	~AirSystem();
	void DisplayIntakePressure();
	void CalculateAirMassFlow();
private:
	float displacement;
	float gasConstant;
	float airTemperature;
	float intakeEfficiency;
};

