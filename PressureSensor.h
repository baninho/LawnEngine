#pragma once

extern float IntakePressure;

class PressureSensor

{
public:
	PressureSensor();
	~PressureSensor();
	void calcIntakePressure();
private:
	unsigned int sensorVoltageReading;
	float factor;
	float offset;
};

