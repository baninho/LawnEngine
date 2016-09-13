#include "LawnEngine.h"


LawnEngine::LawnEngine()
{
	pressureSensor = new PressureSensor;
	airSystem = new AirSystem;
	crankAngleSensor = new CrankAngleSensor;
	fuelPump = new FuelPump;
	ignitionCoil = new IgnitionCoil;
	ignitionControl = new IgnitionControl;
	injectionValve = new InjectionValve;
	lambdaControl = new LambdaControl;
	lambdaSensor = new LambdaSensor;
	tdcDistinction = new TdcDistinction; 
	dac = new Dac;
	adc = new Adc; 

	for (std::list<fp>::iterator i = slot_init.begin(); i != slot_init.end(); ++i)
	{
		(*i)(LawnEngine::Instance());
	}
}

LawnEngine::~LawnEngine()
{
}

LawnEngine& LawnEngine::Instance() {
	static LawnEngine _instance;
	return _instance;
}

void LawnEngine::run_clocked(double dt_seconds, std::list<fp>& slots)
{
	long long int usec;
	std::chrono::time_point<std::chrono::steady_clock> now;
	std::chrono::duration<double> diff;

	while (true)
	{
		diff = std::chrono::steady_clock::now() - now;

		if (diff.count() >= dt_seconds)
		{
			now = std::chrono::steady_clock::now();

			for (std::list<fp>::iterator i = slot_100us.begin(); i != slot_100us.end(); ++i)
			{
				(*i)(LawnEngine::Instance());
			}
		}

		usec = 1000000 * (dt_seconds - std::chrono::steady_clock::now() - now).count();
		std::this_thread::sleep_for(std::chrono::microseconds(usec));
	}
}

void LawnEngine::run_100us()
{
	run_clocked((double) 0.0001, slot_100us);
}

void LawnEngine::run_1ms()
{
	run_clocked((double) 0.001, slot_1ms);
}

void LawnEngine::run_10ms()
{
	run_clocked((double) 0.01, slot_10ms);
}

void LawnEngine::run_100ms()
{
	run_clocked((double) 0.1, slot_100ms);
}

void LawnEngine::run_1000ms()
{
	run_clocked((double) 1, slot_1000ms);
}

void LawnEngine::connect_init(fp function)
{
	slot_init.push_back(function);
}

void LawnEngine::connect_100us(fp function)
{
	slot_100us.push_back(function);
}

void LawnEngine::connect_1ms(fp function)
{
	slot_1ms.push_back(function);
}

void LawnEngine::connect_10ms(fp function)
{
	slot_10ms.push_back(function);
}

void LawnEngine::connect_100ms(fp function)
{
	slot_100ms.push_back(function);
}

void LawnEngine::connect_1000ms(fp function)
{
	slot_1000ms.push_back(function);
	printf("\n connect 1 second task");
}

void run_100us(LawnEngine lawnEngine)
{
	lawnEngine.run_100us();
}

void run_1ms(LawnEngine lawnEngine)
{
	lawnEngine.run_1ms();
}

void run_10ms(LawnEngine lawnEngine)
{
	lawnEngine.run_10ms();
}

void run_100ms(LawnEngine lawnEngine)
{
	lawnEngine.run_100ms();
}

void run_1000ms(LawnEngine lawnEngine)
{
	lawnEngine.run_1000ms();
}

void calcIntakePressure(LawnEngine lawnEngine)
{
	lawnEngine.pressureSensor->calcIntakePressure();
}

void displayIntakePressure(LawnEngine lawnEngine) 
{
	lawnEngine.airSystem->DisplayIntakePressure();
}

void updateAdc(LawnEngine lawnEngine)
{
	lawnEngine.adc->Update();
}

void calcAirSystem(LawnEngine lawnEngine)
{
	lawnEngine.airSystem->Calc();
}

int main()
{
	LawnEngine lawnEngine = LawnEngine::Instance();

	lawnEngine.connect_10ms(&calcIntakePressure);
	lawnEngine.connect_10ms(&calcAirSystem);
	lawnEngine.connect_100ms(&displayIntakePressure);
	lawnEngine.connect_100us(&updateAdc);

	std::thread thread_100us(run_100us, lawnEngine);
	std::thread thread_1ms(run_1ms, lawnEngine);
	std::thread thread_10ms(run_10ms, lawnEngine);
	std::thread thread_100ms(run_100ms, lawnEngine);
	std::thread thread_1000ms(run_1000ms, lawnEngine);
	
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1000));
	}
}
