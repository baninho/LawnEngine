#include "LambdaSensor.h"

bool rich = false;
float lambdaVoltage = 0;

LambdaSensor::LambdaSensor()
{
	stoichVoltage = 63;
}


LambdaSensor::~LambdaSensor()
{
}

void LambdaSensor::CalcLambdaSensor() 
{
	rich = lambdaVoltageReading > stoichVoltage;
}