#include "stdafx.h"
#include "SpiritAutoProtect.h"


SpiritAutoProtect::SpiritAutoProtect()
{
}


SpiritAutoProtect::~SpiritAutoProtect()
{
}

void SpiritAutoProtect::setLowValInMaxLifePercent(UINT lowValInMaxLifePercent) {
	this->lowValInMaxLifePercent = lowValInMaxLifePercent;
}

UINT SpiritAutoProtect::getLowValInMaxLifePercent() {
	return this->lowValInMaxLifePercent;
}

void  SpiritAutoProtect::setAddValInMaxLifePercent(UINT addValInMaxLifePercent) {
	this->addValInMaxLifePercent = addValInMaxLifePercent;
}

UINT SpiritAutoProtect::getAddValInMaxLifePercent() {
	return this->addValInMaxLifePercent;
}

void SpiritAutoProtect::setLowValInMaxStrengthPercent(UINT lowValInMaxStrengthPercent) {
	this->lowValInMaxStrengthPercent = lowValInMaxStrengthPercent;
}

UINT SpiritAutoProtect::getLowValInMaxStrengthPercent() {
	return this->lowValInMaxStrengthPercent;
}

void SpiritAutoProtect::setAddValInMaxStrengthPercent(UINT addValInMaxStrengthPercent) {
	this->addValInMaxStrengthPercent = addValInMaxStrengthPercent;
}

UINT SpiritAutoProtect::getAddValInMaxStrengthPercent() {
	return this->addValInMaxStrengthPercent;
}

void SpiritAutoProtect::setLowValInMaxInternalforcePercent(UINT lowValInMaxInternalforcePercent) {
    this->lowValInMaxInternalforcePercent = lowValInMaxInternalforcePercent;
}

UINT SpiritAutoProtect::getLowValInMaxInternalforcePercent() {
	return this->lowValInMaxInternalforcePercent;
}

void SpiritAutoProtect::setAddValInMaxInternalforcePercent(UINT addValInMaxInternalforcePercent) {
	this->addValInMaxInternalforcePercent = addValInMaxInternalforcePercent;
}

UINT SpiritAutoProtect::getAddValInMaxInternalforcePercent() {
	return this->addValInMaxInternalforcePercent;
}
