#include "Vector.h"
////////////////////////////////////////////////////////
//构造方法
////////////////////////////////////////////////////////
CVector::CVector(int count/* =3 */)
{
	this->mElement=new double[count];
	for(int i=1;i<this->length;i++)
		this->mElement[i]=0;
	this->mElement[0]=1;
	this->length=count;
	this->IsColumn=true;
}
CVector::CVector(double *p,int count,bool isCol/* =true */)
{
	this->mElement=new double[count];
	this->length=count;
	this->IsColumn=isCol; 
}
CVector::CVector(CVector &c)
{
	this->mElement=new double[c.length];
	this->length=c.length;
	this->IsColumn=c.IsColumn;
}

CVector::~CVector(void)
{
	if(this->mElement) delete[] mElement;
}

///////////////////////////////////////////////////////////////////////////////
//功能函数
///////////////////////////////////////////////////////////////////////////////
CVector CVector::CrossProduct(CVector &vec)
{
	if(vec.length=3&&vec.length==this->length)
	{
		CVector temp;
		temp[0]=this->mElement[1]*vec[2]-this->mElement[2]*vec[1];
		temp[1]=this->mElement[2]*vec[0]-this->mElement[0]*vec[2];
		temp[2]=this->mElement[0]*vec[1]-this->mElement[1]*vec[0];

		return temp;
	}
	else
	{
		throw MatrixSizeException();
	}
}

CMatrix CVector::MatrixProduct(CVector &vec)
{
	if(vec.length==this->length)
	{
		if(!vec.IsColumn&&this->IsColumn)
		{
			CMatrix temp1=CMatrix(this->mElement,this->length,1);
			CMatrix temp2=CMatrix(vec.mElement,1,this->length);
			return temp1*temp2;
		}
		else if(vec.IsColumn&&!this->IsColumn)
		{
			CMatrix temp1=CMatrix(this->mElement,1,this->length);
			CMatrix temp2=CMatrix(vec.mElement,this->length,1);
			return temp1*temp2;
		}
		else
		{
			return CMatrix::DiagMatrix(this->length,(*this)*vec);
		}

	}
	else
	{
		throw MatrixSizeException();
	}

}

double CVector::Mod()
{
	double sum=0;
	for(int i=0;i<this->length;i++)
		sum+=pow((*this)[i],2);	
	return sqrt(sum);
}

void CVector::Normalize()
{
	double sum=this->Mod();

	if(sum!=0.0)
	{
		double f=1.0/sum;
		for(int i=0;i<this->length;i++)
			this->mElement[i]*=f;
	}
}

///////////////////////////////////////////////////////////////////////////////
//重载运算符
///////////////////////////////////////////////////////////////////////////////

CVector& CVector::operator= (CVector &vec)
{
	if(&vec==this)
		return *this;

	if(this->mElement)
		delete[] mElement;
	this->mElement=new double[vec.length];
	this->length=vec.length;
	this->IsColumn=vec.IsColumn;

	for(int i=0;i<this->length;i++)
		this->mElement[i]=vec.mElement[i];

	return This;

}

inline double& CVector::operator[](int i)
{
	if(i>this->length||i<0)
		throw MatrixSizeException();
	else
		return this->mElement[i];
}

double CVector::operator*(CVector& vec)
{
	if(this->length!=vec.length)
		throw MatrixSizeException();

	double sum=0.0;
	for(int i=0;i<this->length;i++)
		sum+=(*this)[i]*vec[i];
	return sum;
}

CVector CVector::operator*(double num)
{
	CVector temp=CVector(this->length);
	for(int i=0;i<this->length;i++)
		temp[i]=(*this)[i]*num;

	return temp;
}

CVector CVector::operator+(CVector& vec)
{
	if(this->length!=vec.length)
		throw MatrixSizeException();

	CVector temp=CVector(this->length);
	for(int i=0;i<this->length;i++)
		temp[i]=(*this)[i]+vec[i];

	return temp;
}

CVector CVector::operator-(CVector& vec)
{
	if(this->length!=vec.length)
		throw MatrixSizeException();

	CVector temp=CVector(this->length);

	for(int i=0;i<this->length;i++)
		temp[i]=(*this)[i]-vec[i];

	return temp;
}

CVector CVector::operator-()
{
	for(int i=0;i<this->length;i++)
		(*this)[i]*=-1;

	return (*this);
}

bool CVector::operator==(CVector &vec)
{
	if(this->length!=vec.length)
		throw MatrixSizeException();

	bool result=true;
	for(int i=0;i<this->length;i++)
	{
		if(this->mElement[i]!=vec[i])
		{
			result=false;
			break;
		}
	}
	return result;
}
///////////////////////////////////////////////////////////////////////////////
//static method
///////////////////////////////////////////////////////////////////////////////
CVector CVector::CreateZeroVector(int n)
{
	CVector t(n);
	t[0]=0;
	return t;
}

double CVector::GetDistance(CVector &vec1,CVector &vec2)
{
	if(vec1.length!=vec2.length)
		throw MatrixSizeException();

	double sum=0;
	for(int i=0;i<vec1.length;i++)
		sum+=pow(vec1[i]-vec2[i],2);

	return sqrt(sum);
}