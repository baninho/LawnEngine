le: bin/LawnEngine.o bin/Adc.o bin/AirSystem.o bin/CrankAngleSensor.o bin/Dac.o bin/EnginePositionManager.o bin/FuelPump.o bin/IgnitionCoil.o bin/IgnitionControl.o bin/InjectionValve.o bin/LambdaControl.o bin/LambdaSensor.o bin/PressureSensor.o bin/TdcDistinction.o
	g++ -o bin/le -std=c++11 -lstdc++ bin/LawnEngine.o bin/Adc.o bin/AirSystem.o bin/CrankAngleSensor.o bin/Dac.o bin/EnginePositionManager.o bin/FuelPump.o bin/IgnitionCoil.o bin/IgnitionControl.o bin/InjectionValve.o bin/LambdaControl.o bin/LambdaSensor.o bin/PressureSensor.o bin/TdcDistinction.o

bin/LawnEngine.o: LawnEngine.cpp LawnEngine.h
	g++ -c -o bin/LawnEngine.o -std=c++11 -lstdc++ LawnEngine.cpp
bin/Adc.o: Adc.cpp Adc.h
	gcc -c -o bin/Adc.o Adc.cpp

bin/AirSystem.o: AirSystem.cpp AirSystem.h
	gcc -c -o bin/AirSystem.o AirSystem.cpp

bin/CrankAngleSensor.o: CrankAngleSensor.cpp CrankAngleSensor.h
	gcc -c -o bin/CrankAngleSensor.o CrankAngleSensor.cpp

bin/Dac.o: Dac.cpp Dac.h
	gcc -c -o bin/Dac.o Dac.cpp

bin/EnginePositionManager.o: EnginePositionManager.cpp EnginePositionManager.h
	gcc -c -o bin/EnginePositionManager.o EnginePositionManager.cpp

bin/FuelPump.o: FuelPump.cpp FuelPump.h
	gcc -c -o bin/FuelPump.o FuelPump.cpp

bin/IgnitionCoil.o: IgnitionCoil.cpp IgnitionCoil.h
	gcc -c -o bin/IgnitionCoil.o IgnitionCoil.cpp

bin/IgnitionControl.o: IgnitionControl.cpp IgnitionControl.h
	gcc -c -o bin/IgnitionControl.o IgnitionControl.cpp

bin/InjectionValve.o: InjectionValve.cpp InjectionValve.h
	gcc -c -o bin/InjectionValve.o InjectionValve.cpp

bin/LambdaControl.o: LambdaControl.cpp LambdaControl.h
	gcc -c -o bin/LambdaControl.o LambdaControl.cpp

bin/LambdaSensor.o: LambdaSensor.cpp LambdaSensor.h
	gcc -c -o bin/LambdaSensor.o LambdaSensor.cpp

bin/PressureSensor.o: PressureSensor.cpp PressureSensor.h
	gcc -c -o bin/PressureSensor.o PressureSensor.cpp

bin/TdcDistinction.o: TdcDistinction.cpp TdcDistinction.h
	gcc -c -o bin/TdcDistinction.o TdcDistinction.cpp
