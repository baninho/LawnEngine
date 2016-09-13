#pragma once

#include <stdio.h>
#include <chrono>
#include <list>
#include <thread>

#include "PressureSensor.h"
#include "AirSystem.h"
#include "CrankAngleSensor.h"
#include "FuelPump.h"
#include "IgnitionCoil.h"
#include "IgnitionControl.h"
#include "InjectionValve.h"
#include "LambdaControl.h"
#include "LambdaSensor.h"
#include "TdcDistinction.h"
#include "Dac.h"
#include "Adc.h"

class LawnEngine
{
	typedef void(*fp)(LawnEngine lawnEngine);

public:
	LawnEngine();
	~LawnEngine();
	static LawnEngine& Instance();

	void run_clocked(double dt_seconds, std::list<fp>& slots);
	void run_100us();
	void run_1ms();
	void run_10ms();
	void run_100ms();
	void run_1000ms();
	void connect_init(fp function);
	void connect_100us(fp function);
	void connect_1ms(fp function);
	void connect_10ms(fp function);
	void connect_100ms(fp function);
	void connect_1000ms(fp function);

	PressureSensor* pressureSensor;
	AirSystem* airSystem;
	CrankAngleSensor* crankAngleSensor;
	FuelPump* fuelPump;
	IgnitionCoil* ignitionCoil;
	IgnitionControl* ignitionControl;
	InjectionValve* injectionValve;
	LambdaControl* lambdaControl;
	LambdaSensor* lambdaSensor;
	TdcDistinction* tdcDistinction;
	Dac* dac;
	Adc* adc;

private:
	std::list<fp> slot_init;
	std::list<fp> slot_100us;
	std::list<fp> slot_1ms;
	std::list<fp> slot_10ms;
	std::list<fp> slot_100ms;
	std::list<fp> slot_1000ms;
};

