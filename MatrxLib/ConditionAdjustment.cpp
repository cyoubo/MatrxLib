#include "ConditionAdjustment.h"

//////////////////////////////////////////////////////////////////////////
//���췽������
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
//���ܺ�������
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
//����ӿڲ���
//////////////////////////////////////////////////////////////////////////
double ConditionAdjustment::Calculate()
{
	return AbstructAdjustment::getRmse();
}

