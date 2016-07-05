#pragma once

extern float IntakePressure;
extern unsigned char pressureVoltageReading;

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

