#pragma once

extern float IntakePressure;
extern unsigned char sensorVoltageReading;

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

