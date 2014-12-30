#include "ConditionAdjustment.h"

//////////////////////////////////////////////////////////////////////////
//构造方法部分
//////////////////////////////////////////////////////////////////////////
ConditionAdjustment::ConditionAdjustment(CMatrix a,CMatrix w,CMatrix p)
	:AbstructAdjustment(p,NULL,a.getColCount()-a.getRowCount())
{
	this->A=new CMatrix(a);
	this->W=new CMatrix(w);
	this->IsCalculated=false;
}
ConditionAdjustment::~ConditionAdjustment(void)
{
	if(this->A) delete this->A;
	if(this->W) delete this->W;
}
//////////////////////////////////////////////////////////////////////////
//功能函数部分
//////////////////////////////////////////////////////////////////////////
CMatrix ConditionAdjustment::getAMatrix()
{
	return CMatrix(This_(A));
}

CMatrix ConditionAdjustment::getWMatrix()
{
	return CMatrix(This_(W));
}

void ConditionAdjustment::setObservationMatrix(CMatrix *obs)
{
	
	this->L=new CMatrix((*obs));
}
//////////////////////////////////////////////////////////////////////////
//抽象接口部分
//////////////////////////////////////////////////////////////////////////
double ConditionAdjustment::Calculate()
{
	return AbstructAdjustment::getRmse();
}

