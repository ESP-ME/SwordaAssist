#pragma once
class SpiritAutoProtect
{
private:
	UINT lowValInMaxLifePercent = NULL;
	UINT addValInMaxLifePercent = NULL;
	UINT lowValInMaxStrengthPercent = NULL;
	UINT addValInMaxStrengthPercent = NULL;
	UINT lowValInMaxInternalforcePercent = NULL;
	UINT addValInMaxInternalforcePercent = NULL;
public:
	SpiritAutoProtect();
	~SpiritAutoProtect();
	void setLowValInMaxLifePercent(UINT lowValInMaxLifePercent);
	UINT getLowValInMaxLifePercent();
	void setAddValInMaxLifePercent(UINT addValInMaxLifePercent);
	UINT getAddValInMaxLifePercent();
	void setLowValInMaxStrengthPercent(UINT lowValInMaxStrengthPercent);
	UINT getLowValInMaxStrengthPercent();
	void setAddValInMaxStrengthPercent(UINT addValInMaxStrengthPercent);
	UINT getAddValInMaxStrengthPercent();
	void setLowValInMaxInternalforcePercent(UINT lowValInMaxInternalforcePercent);
	UINT getLowValInMaxInternalforcePercent();
	void setAddValInMaxInternalforcePercent(UINT addValInMaxInternalforcePercent);
	UINT getAddValInMaxInternalforcePercent();
};

