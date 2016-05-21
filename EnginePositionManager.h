#pragma once

extern float EngineSpeed;
extern bool CogFacingSensor;

class EnginePositionManager
{
public:
	EnginePositionManager();
	~EnginePositionManager();
	void CalculateEngineSpeed();
private:
	int cogCount;
};

