#pragma once
#include <cstdlib>

extern bool CogFacingSensor;

class CrankAngleSensor
{
public:
	CrankAngleSensor();
	~CrankAngleSensor();
	void CalcCrankSensor();
private:
	int sensorVoltageReading;
	int minDetectionVoltage;
};

