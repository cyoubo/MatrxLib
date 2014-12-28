#include "AbstructAdjustment.h"


AbstructAdjustment::AbstructAdjustment(void)
{
	this->IsCalculated=false;
	this->N=0;
	this->T=0;
	this->P=0;
	this->V=0;
	this->Rmse=0;
}

AbstructAdjustment::AbstructAdjustment(int n,int r)
{
	this->IsCalculated=false;
	this->N=n;
	this->T=r;
	this->V=new CMatrix(this->N,1);
	this->P=0;
	this->Rmse=0;
}

AbstructAdjustment::AbstructAdjustment(CMatrix P,CMatrix L,int t)
{
	this->P=new CMatrix(P);
	this->L=new CMatrix(L);
	this->N=this->P->getRowCount();
	this->T=t;
}

AbstructAdjustment::~AbstructAdjustment(void)
{
	if(this->V) delete V;
	if(this->P) delete P;
	if(this->Qvv) delete Qvv;
	if(this->L) delete L;
	if(this->Lg) delete Lg;
}

double AbstructAdjustment::getRmse()
{
	if(IsCalculated)
		return this->Rmse;
	else
		return 0;
}

CMatrix AbstructAdjustment::getCorrectionMatrix()
{
	CMatrix temp(This_(V));
	return temp;
}

CMatrix AbstructAdjustment::getPowerMatrix()
{
	CMatrix temp(This_(P));
	return temp;
}

CMatrix AbstructAdjustment::getCorrectionCoFactorMatrix()
{
	return CMatrix(This_(Qvv));
}

CMatrix AbstructAdjustment::getObservationMatrix()
{
	return CMatrix(This_(L));
}

CMatrix AbstructAdjustment::getObservationCorrectionMatrix(CMatrix *ObservationMatrix/* =NULL */)
{
	if(ObservationMatrix)
		return CMatrix(This_(L)+This_(V));
	else
		return CMatrix((*ObservationMatrix)+This_(V));
}

void AbstructAdjustment::Calculate_Rmse()
{
	if(IsCalculated&&this->V&&this->P)
	{
		this->Rmse=sqrt((V->Transposition()*This_(P)*This_(V))(0,0));
	}
}

