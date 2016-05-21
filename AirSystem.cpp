#include "AirSystem.h"

float AirMassFlow = 0;

AirSystem::AirSystem()
{
	displacement = 0.25;
	gasConstant = 287;
	airTemperature = 325;
	intakeEfficiency = 0.8;
}


AirSystem::~AirSystem()
{
}

void AirSystem::DisplayIntakePressure()
{
	printf("\nIntake Pressure: %f", IntakePressure);
}

void AirSystem::CalculateAirMassFlow() 
{
	AirMassFlow = EngineSpeed * IntakePressure * displacement / gasConstant / airTemperature * intakeEfficiency;
}
