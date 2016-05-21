#pragma once
extern float IntakePressure;

class PressureSensor

{
public:
	PressureSensor();
	~PressureSensor();
private:
	void calcIntakePressure();
	int sensorVoltageReading;
	float factor;
	float offset;
};

