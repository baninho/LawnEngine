#pragma once
#include <cstdlib>

extern unsigned short angleVoltageReading;
extern bool cogFacingSensor;

class CrankAngleSensor
{
public:
	CrankAngleSensor();
	~CrankAngleSensor();
	void CalcCrankSensor();
private:
	int minDetectionVoltage;
};

