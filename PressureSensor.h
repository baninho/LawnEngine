#pragma once
extern float IntakePressure;

class PressureSensor

{
public:
	PressureSensor();
	~PressureSensor();
	void calcIntakePressure();
private:
	int sensorVoltageReading;
	float factor;
	float offset;
};

