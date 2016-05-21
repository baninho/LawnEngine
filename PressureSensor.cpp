#include "PressureSensor.h"



PressureSensor::PressureSensor()
{
	factor = 0.02;
	offset = 0;
}


PressureSensor::~PressureSensor()
{
}

void PressureSensor::calcIntakePressure()
{
	IntakePressure = factor * (float)sensorVoltageReading + offset;
}
