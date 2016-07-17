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
	AirMassFlow = EngineSpeed * IntakePressure * displacement / gasConstant / airTemperature * intakeEfficiency;
}
