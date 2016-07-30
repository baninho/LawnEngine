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
	float _nEng, _intakeP, _airMF, _displace, _r, _airCyl;
	
	_nEng = EngineSpeed / 60; // 1/s
	_intakeP = IntakePressure * 100; // Pa
	_displace = displacement / 1000; // m3

	_airCyl = _intakeP * _displace / _r / airTemperature * intakeEfficiency; // kg
	_airMF = 0.5 * _nEng * _airCyl; // kg/s

	AirMassPerCyl = _airCyl * 1000000; // mg
	AirMassFlow = _airMF * 3600; // kg/h
}
