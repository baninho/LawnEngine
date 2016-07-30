#pragma once

extern unsigned short lambdaVoltageReading;
extern float lambdaVoltage;
extern bool rich;

class LambdaSensor
{
public:
	LambdaSensor();
	~LambdaSensor();
	void CalcLambdaSensor();
private:
	unsigned short stoichVoltage;
};

