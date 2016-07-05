#include "CrankAngleSensor.h"

bool cogFacingSensor = false;

CrankAngleSensor::CrankAngleSensor()
{
	minDetectionVoltage = 127;
}


CrankAngleSensor::~CrankAngleSensor()
{
}

void CrankAngleSensor::CalcCrankSensor() 
{
	static bool _dontToggle = false;
	cogFacingSensor = abs(angleVoltageReading) > minDetectionVoltage || _dontToggle;
	_dontToggle = abs(angleVoltageReading) > minDetectionVoltage;
}