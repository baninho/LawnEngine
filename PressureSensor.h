#pragma once

extern float IntakePressure;
extern unsigned short pressureVoltageReading;

class PressureSensor

{
public:
	PressureSensor();
	~PressureSensor();
	void calcIntakePressure();
private:
	float factor;
	float offset;
};

