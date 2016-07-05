#pragma once

extern float EngineSpeed;
extern bool cogFacingSensor;

class EnginePositionManager
{
public:
	EnginePositionManager();
	~EnginePositionManager();
	void CalculateEngineSpeed();
private:
	int cogCount;
};

