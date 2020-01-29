#pragma once
class Spirit
{
private:
	//等级
	UINT grade;
	//防御力
	UINT defense;
	//攻击力
	UINT aggressivity;
	//身法
	UINT positioning;
	//生命 
	UINT life;
	//体力
	UINT strength;
	//内力
	UINT internalforce;
	//金钱
	UINT money;
public:
	Spirit();
	~Spirit();
	void setAllProperty(UINT grade, UINT defense, UINT aggressivity, UINT positioning, UINT life,
		UINT strength, UINT internalforce, UINT money);
	void setGrade(UINT grade);
	void setDefense(UINT defense);
	void setAggressivity(UINT aggressivity);
	void setPositioning(UINT positioning);
	void setLife(UINT life);
	void setStrength(UINT strength);
	void setInternalforce(UINT internalforce);
	void setMoney(UINT money);
	UINT getGrade();
	UINT getDefense();
	UINT getAggressivity();
	UINT getPositioning();
	UINT getLife();
	UINT getStrength();
	UINT getInternalforce();
	UINT getMoney();
};

