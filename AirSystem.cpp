#include "AirSystem.h"

float AirMassFlow = 0, AirMassPerCyl = 0;
float FuelMassPerCyl = 0, InjectedFuelMassDes = 0;

AirSystem::AirSystem()
{
	airTemperature = 325.0f;
	intakeEfficiency = 0.8f;
	m_WallFilmMass = 0.0f;
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

void AirSystem::CalculateFuelInj()
{
	FuelMassPerCyl = AirMassPerCyl / LamdaDesired / AirFuelRatio;
	InjectedFuelMassDes = FuelMassPerCyl / (1 - m_facWall);
}

void AirSystem::CalculateFuelWallFilm()
{
	// TODO: get fac and evap from lookup table depending on wall film mass in Lookup method
	// TODO: use actual fuel mass instead of desired (after correction in lambda control)
	float _wallEvap;
	
	_wallEvap = 0;

	m_WallFilmMass = m_WallFilmMass + InjectedFuelMassDes * (m_facWall) - _wallEvap;
}


void AirSystem::Lookup() 
{
	// TOOD: Move all lookups together here
	m_facWall = 0;
}

void AirSystem::Calc()
{
	Lookup();
	CalculateAirMassFlow();
	CalculateFuelInj();
	CalculateFuelWallFilm();
}