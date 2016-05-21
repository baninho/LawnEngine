#pragma once

extern bool Lean;
extern bool Rich;

class LambdaSensor
{
public:
	LambdaSensor();
	~LambdaSensor();
	void CalcLambdaSensor();
private:
	int sensorVoltageReading;
	int stoichVoltage;
};

