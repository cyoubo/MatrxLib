#include "IndirectionAdjustment.h"


IndirectionAdjustment::IndirectionAdjustment(void)
{}

IndirectionAdjustment::IndirectionAdjustment(CMatrix b,CMatrix inti,CMatrix coe,CMatrix p,CMatrix l)
	:AbstructAdjustment(p,l,b.getColCount())
{
	this->B=new CMatrix(b);
	this->Inti=new CMatrix(inti);
	this->Coe=new CMatrix(coe);

	this->IsCalculated=false;
}

IndirectionAdjustment::~IndirectionAdjustment(void)
{
	if(this->B) delete B;
	if(this->Inti) delete Inti;
	if(this->Coe) delete Coe;
}

CMatrix IndirectionAdjustment::getBMatrix()
{
	return CMatrix(This_(B));
}

CMatrix IndirectionAdjustment::getInit()
{
	return CMatrix(This_(Inti));
}

CMatrix IndirectionAdjustment::getCoe()
{
	return CMatrix(This_(Coe));
}

double IndirectionAdjustment::Calculate()
{
	return this->Rmse;
}