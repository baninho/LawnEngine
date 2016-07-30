#pragma once
#include <stdio.h>

extern float IntakePressure;							// From Pressure sensor
extern float EngineSpeed;								// From EPM
extern float LamdaDesired;								// From Lambda control

extern float AirMassFlow, AirMassPerCyl;				// Export Air
extern float FuelMassPerCyl, InjectedFuelMassDes;		// Export Fuel


class AirSystem
{
public:
	AirSystem();
	~AirSystem();
	void DisplayIntakePressure();
	void CalculateAirMassFlow();
	void CalculateFuelInj();
	void CalculateFuelWallFilm();
	void Lookup();
	void Calc();
private:
	const float displacement = 0.25f, gasConstant = 287.0f, AirFuelRatio = 15;
	float airTemperature, intakeEfficiency;
	float m_WallFilmMass, m_facWall;
};

