#include "AirSystem.h"

float AirMassFlow = 0;

AirSystem::AirSystem()
{
	displacement = 0.25f;
	gasConstant = 287.0f;
	airTemperature = 325.0f;
	intakeEfficiency = 0.8f;
}


AirSystem::~AirSystem()
{
}

void AirSystem::DisplayIntakePressure()
{
	printf("\nIntake Pressure: %0.3f bar", IntakePressure);
}

void AirSystem::CalculateAirMassFlow() 
{
	float _nEng, _intakeP, _airMF, _displace, _r;
	
	_nEng = EngineSpeed / 60; // 1/s
	_intakeP = IntakePressure * 100; // Pa
	_displace = displacement / 1000; // m3
	
	_airMF = _nEng * _intakeP * _displace / _r / airTemperature * intakeEfficiency; // kg/s
	AirMassFlow = _airMF * 3600; // kg/h
}
