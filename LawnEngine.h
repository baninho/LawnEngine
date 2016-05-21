#pragma once
#include <stdio.h>
#include <chrono>
#include <list>

typedef void(*fp)();

class LawnEngine
{
public:
	LawnEngine();
	~LawnEngine();
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
private:
	std::list<fp> slot_init;
	std::list<fp> slot_100us;
	std::list<fp> slot_1ms;
	std::list<fp> slot_10ms;
	std::list<fp> slot_100ms;
	std::list<fp> slot_1000ms;
};

