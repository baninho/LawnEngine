le: bin/LawnEngine.o bin/Adc.o bin/AirSystem.o bin/CrankAngleSensor.o bin/Dac.o bin/EnginePositionManager.o bin/FuelPump.o bin/IgnitionCoil.o bin/IgnitionControl.o bin/InjectionValve.o bin/LambdaControl.o bin/LambdaSensor.o bin/PressureSensor.o bin/TdcDistinction.o
	gcc -o bin/le -std=c++11 bin/LawnEngine.o bin/Adc.o bin/AirSystem.o bin/CrankAngleSensor.o bin/Dac.o bin/EnginePositionManager.o bin/FuelPump.o bin/IgnitionCoil.o bin/IgnitionControl.o bin/InjectionValve.o bin/LambdaControl.o bin/LambdaSensor.o bin/PressureSensor.o bin/TdcDistinction.o

LawnEngine.o: LawnEngine.cpp LawnEngine.h
	gcc -c -o bin/LawnEngine.o -std=c++11 LawnEngine.cpp

Adc.o: Adc.cpp Adc.h
	gcc -c -o bin/Adc.o Adc.cpp

AirSystem.o: AirSystem.cpp AirSystem.h
	gcc -c -o bin/AirSystem.o AirSystem.cpp

CrankAngleSensor.o: CrankAngleSensor.cpp CrankAngleSensor.h
	gcc -c -o bin/CrankAngleSensor.o CrankAngleSensor.cpp

Dac.o: Dac.cpp Dac.h
	gcc -c -o bin/Dac.o Dac.cpp

EnginePositionManager.o: EnginePositionManager.cpp EnginePositionManager.h
	gcc -c -o bin/EnginePositionManager.o EnginePositionManager.cpp

FuelPump.o: FuelPump.cpp FuelPump.h
	gcc -c -o bin/FuelPump.o FuelPump.cpp

IgnitionCoil.o: IgnitionCoil.cpp IgnitionCoil.h
	gcc -c -o bin/IgnitionCoil.o IgnitionCoil.cpp

IgnitionControl.o: IgnitionControl.cpp IgnitionControl.h
	gcc -c -o bin/IgnitionControl.o IgnitionControl.cpp

InjectionValve.o: InjectionValve.cpp InjectionValve.h
	gcc -c -o bin/InjectionValve.o InjectionValve.cpp

LambdaControl.o: LambdaControl.cpp LambdaControl.h
	gcc -c -o bin/LambdaControl.o LambdaControl.cpp

LambdaSensor.o: LambdaSensor.cpp LambdaSensor.h
	gcc -c -o bin/LambdaSensor.o LambdaSensor.cpp

PressureSensor.o: PressureSensor.cpp PressureSensor.h
	gcc -c -o bin/PressureSensor.o PressureSensor.cpp

TdcDistinction.o: TdcDistinction.cpp TdcDistinction.h
	gcc -c -o bin/TdcDistinction.o TdcDistinction.cpp
