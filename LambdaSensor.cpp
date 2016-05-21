#include "LambdaSensor.h"

bool Rich = false;
bool Lean = false;

LambdaSensor::LambdaSensor()
{
	stoichVoltage = 63;
}


LambdaSensor::~LambdaSensor()
{
}

void LambdaSensor::CalcLambdaSensor() 
{
	Rich = sensorVoltageReading > stoichVoltage;
	Lean = !Rich;
}