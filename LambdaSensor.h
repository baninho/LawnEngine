#pragma once

extern unsigned short lambdaVoltageReading;
extern float lambdaVoltage;

class LambdaSensor
{
public:
	LambdaSensor();
	~LambdaSensor();
	void CalcLambdaSensor();
private:
	unsigned short stoichVoltage;
};

