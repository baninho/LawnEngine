#include "LawnEngine.h"



LawnEngine::LawnEngine()
{
	connect_100us(&(pressureSensor.calcIntakePressure));
	connect_1000ms(&(airSystem.DisplayIntakePressure));
	for (std::list<fp>::iterator i = slot_init.begin(); i != slot_init.end(); ++i)
		(*i)();
}


LawnEngine::~LawnEngine()
{
}

void LawnEngine::run_100us()
{
	for (std::list<fp>::iterator i = slot_100us.begin(); i != slot_100us.end(); ++i)
		(*i)();
}

void LawnEngine::run_1ms()
{
	for (std::list<fp>::iterator i = slot_1ms.begin(); i != slot_1ms.end(); ++i)
		(*i)();
}

void LawnEngine::run_10ms()
{
	for (std::list<fp>::iterator i = slot_10ms.begin(); i != slot_10ms.end(); ++i)
		(*i)();
}

void LawnEngine::run_100ms()
{
	for (std::list<fp>::iterator i = slot_100ms.begin(); i != slot_100ms.end(); ++i)
		(*i)();
}

void LawnEngine::run_1000ms()
{
	for (std::list<fp>::iterator i = slot_1000ms.begin(); i != slot_1000ms.end(); ++i)
		(*i)();
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

void printText() {
	printf("\n run 1 second task");
}

int main()
{
	LawnEngine lawnEngine;
	std::chrono::time_point<std::chrono::steady_clock> now;
	std::chrono::duration<double> diff;
	int count1 = 0, count10 = 0, count100 = 0, count1000 = 0;

	now = std::chrono::steady_clock::now();

	lawnEngine.connect_1000ms(&printText);

	while (true) {
		diff = std::chrono::steady_clock::now() - now;
		if (diff.count() >= 0.0001) {
			now = std::chrono::steady_clock::now();
			lawnEngine.run_100us();
			++count1;
		}
		else continue;
		if (count1 % 10 == 0) {
			lawnEngine.run_1ms();
			++count10;
		}
		else continue;
		if (count10 % 10 == 0) {
			lawnEngine.run_10ms();
			++count100;
		}
		else continue;
		if (count100 % 10 == 0) {
			lawnEngine.run_100ms();
			++count1000;
		}
		else continue;
		if (count1000 % 10 == 0) {
			lawnEngine.run_1000ms();
		}
		else continue;
	}


}
