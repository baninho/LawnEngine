#include "CrankAngleSensor.h"

bool CogFacingSensor = false;

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
	CogFacingSensor = abs(sensorVoltageReading) > minDetectionVoltage || _dontToggle;
	_dontToggle = abs(sensorVoltageReading) > minDetectionVoltage;
}