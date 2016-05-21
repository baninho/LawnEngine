#pragma once

extern float EngineSpeed;

class EnginePositionManager
{
public:
	EnginePositionManager();
	~EnginePositionManager();
	void CalculateEngineSpeed();
private:
	int cogCount;
};

