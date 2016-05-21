#include "PressureSensor.h"

float IntakePressure = 0;

PressureSensor::PressureSensor()
{
	factor = 0.02;
	offset = 0.1;
	sensorVoltageReading = 0;
}


PressureSensor::~PressureSensor()
{
}

void PressureSensor::calcIntakePressure()
{
	IntakePressure = factor * (float)sensorVoltageReading + offset;
}
