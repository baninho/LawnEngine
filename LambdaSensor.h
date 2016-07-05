#pragma once

extern unsigned short lambdaVoltageReading;

class LambdaSensor
{
public:
	LambdaSensor();
	~LambdaSensor();
	void CalcLambdaSensor();
private:
	unsigned short stoichVoltage;
	unsigned char rich;
};

