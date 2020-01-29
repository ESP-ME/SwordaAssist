#include "stdafx.h"
#include "Spirit.h"


Spirit::Spirit()
{
}


Spirit::~Spirit()
{
}

void Spirit::setAllProperty(UINT grade, UINT defense, UINT aggressivity, UINT positioning, UINT life,
	UINT strength, UINT internalforce, UINT money) {
	this->grade = grade;
	this->defense = defense;
	this->aggressivity = aggressivity;
	this->positioning = positioning;
	this->life = life;
	this->strength = strength;
	this->internalforce = internalforce;
	this->money = money;
}

void Spirit::setGrade(UINT grade) {
	this->grade = grade;
}
void Spirit::setDefense(UINT defense) {
	this->defense = defense;
}
void Spirit::setAggressivity(UINT aggressivity) {
	this->aggressivity = aggressivity;
}
void Spirit::setPositioning(UINT positioning) {
	this->positioning = positioning;
}
void Spirit::setLife(UINT life) {
	this->life = life;
}
void Spirit::setStrength(UINT strength) {
	this->strength = strength;
}
void Spirit::setInternalforce(UINT internalforce) {
	this->internalforce = internalforce;
}
void Spirit::setMoney(UINT money) {
	this->money = money;
}
UINT Spirit::getGrade() {
	return this->grade;
}
UINT Spirit::getDefense() {
	return this->defense;
}
UINT Spirit::getAggressivity() {
	return this->aggressivity;
}
UINT Spirit::getPositioning() {
	return this->positioning;
}
UINT Spirit::getLife() {
	return this->life;
}
UINT Spirit::getStrength() {
	return this->strength;
}
UINT Spirit::getInternalforce() {
	return this->internalforce;
}
UINT Spirit::getMoney() {
	return this->money;
}

