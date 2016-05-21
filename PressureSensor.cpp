#include "PressureSensor.h"

float IntakePressure = 0;

PressureSensor::PressureSensor()
{
	factor = 0.02f;
	offset = 0.1f;
	sensorVoltageReading = 0u;
}


PressureSensor::~PressureSensor()
{
}

void PressureSensor::calcIntakePressure()
{
	IntakePressure = factor * (float)sensorVoltageReading + offset;
}
