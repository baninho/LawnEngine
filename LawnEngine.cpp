#include "LawnEngine.h"


LawnEngine::LawnEngine()
{
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

void LawnEngine::run_100us()
{
	long long int usec;
	std::chrono::time_point<std::chrono::steady_clock> now;
	std::chrono::duration<double> diff;

	while (true)
	{
		diff = std::chrono::steady_clock::now() - now;

		if (diff.count() >= 0.0001)
		{
			now = std::chrono::steady_clock::now();

			for (std::list<fp>::iterator i = slot_100us.begin(); i != slot_100us.end(); ++i)
			{
				(*i)(LawnEngine::Instance());
			}
		}

		usec = 50 - 1000000 * (std::chrono::steady_clock::now() - now).count();
		std::this_thread::sleep_for(std::chrono::microseconds(usec));
	}
}

void LawnEngine::run_1ms()
{
	long long int usec;
	std::chrono::time_point<std::chrono::steady_clock> now;
	std::chrono::duration<double> diff;

	while (true)
	{
		diff = std::chrono::steady_clock::now() - now;

		if (diff.count() >= 0.001)
		{
			now = std::chrono::steady_clock::now();

			for (std::list<fp>::iterator i = slot_1ms.begin(); i != slot_1ms.end(); ++i)
			{
				(*i)(LawnEngine::Instance());
			}
		}

		usec = 500 - 1000000 * (std::chrono::steady_clock::now() - now).count();
		std::this_thread::sleep_for(std::chrono::microseconds(usec));
	}

}

void LawnEngine::run_10ms()
{
	long long int usec;
	std::chrono::time_point<std::chrono::steady_clock> now;
	std::chrono::duration<double> diff;

	while (true)
	{
		diff = std::chrono::steady_clock::now() - now;

		if (diff.count() >= 0.01)
		{
			now = std::chrono::steady_clock::now();

			for (std::list<fp>::iterator i = slot_10ms.begin(); i != slot_10ms.end(); ++i)
			{
				(*i)(LawnEngine::Instance());
			}
		}

		usec = 5000 - 1000000 * (std::chrono::steady_clock::now() - now).count();
		std::this_thread::sleep_for(std::chrono::microseconds(usec));
	}
}

void LawnEngine::run_100ms()
{
	long long int usec;
	std::chrono::time_point<std::chrono::steady_clock> now;
	std::chrono::duration<double> diff;

	while (true)
	{
		diff = std::chrono::steady_clock::now() - now;

		if (diff.count() >= 0.1)
		{
			now = std::chrono::steady_clock::now();

			for (std::list<fp>::iterator i = slot_100ms.begin(); i != slot_100ms.end(); ++i)
			{
				(*i)(LawnEngine::Instance());
			}
		}

		usec = 5000 - 1000000 * (std::chrono::steady_clock::now() - now).count();
		std::this_thread::sleep_for(std::chrono::microseconds(usec));
	}
}

void LawnEngine::run_1000ms()
{
	long long int usec;
	std::chrono::time_point<std::chrono::steady_clock> now;
	std::chrono::duration<double> diff;

	while (true)
	{
		diff = std::chrono::steady_clock::now() - now;

		if (diff.count() >= 1)
		{
			now = std::chrono::steady_clock::now();

			for (std::list<fp>::iterator i = slot_1000ms.begin(); i != slot_1000ms.end(); ++i)
			{
				(*i)(LawnEngine::Instance());
			}
		}

		usec = 50000 - 1000000 * (std::chrono::steady_clock::now() - now).count();
		std::this_thread::sleep_for(std::chrono::microseconds(usec));
	}

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

void calcIntakePressure(LawnEngine lawnEngine) {
	lawnEngine.pressureSensor.calcIntakePressure();
}

void displayIntakePressure(LawnEngine lawnEngine) {
	lawnEngine.airSystem.DisplayIntakePressure();
}

void readLambda(LawnEngine lawnEngine)
{
	lawnEngine.adc.readLambda();
}

void readPressure(LawnEngine lawnEngine)
{
	lawnEngine.adc.readPressure();
}

void readAngle(LawnEngine lawnEngine)
{
	lawnEngine.adc.readAngle();
}

int main()
{
	LawnEngine lawnEngine = LawnEngine::Instance();

	lawnEngine.connect_100us(&readAngle);
	lawnEngine.connect_10ms(&readPressure);
	lawnEngine.connect_10ms(&readLambda);
	lawnEngine.connect_10ms(&calcIntakePressure);
	lawnEngine.connect_1000ms(&displayIntakePressure);

	std::thread thread_100us(run_100us, lawnEngine);
	std::thread thread_1ms(run_1ms, lawnEngine);
	std::thread thread_10ms(run_10ms, lawnEngine);
	std::thread thread_100ms(run_100ms, lawnEngine);
	std::thread thread_1000ms(run_1000ms, lawnEngine);
	
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
