#include "CommonHeader.h"
CMatrix::CMatrix(void)
{

}

CMatrix::~CMatrix(void)
{
	if(mElement!=0)
		delete[] mElement;
}

CMatrix::CMatrix(int row/* =0 */,int col/* =0 */)
{
	mRow=row;mCol=col;
			mElement=new double[row*col];
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++)
					mElement[i*col+j]=(i==j?1:0);
}

CMatrix::CMatrix(const double* values,int row/* =0 */,int col/* =0 */)
{
	mRow=row;mCol=col;
	mElement=new double[mRow*mCol];
	
	for (int i=0;i<mRow*mCol;i++)
		mElement[i]=values[i];
}

CMatrix::CMatrix(CMatrix& matrix)
{
	/*
	if(This.mElement!=0)
		delete[] This.mElement;
	*/
	mElement=new double[matrix.mCol*matrix.mRow];
	for(int i=0;i<matrix.mCol*matrix.mRow;i++)
		This.mElement[i]=matrix.mElement[i];
	
	This.mCol=matrix.mCol;
	This.mRow=matrix.mRow; 
}

//////////////////////////////////////////////////////////////////////////
//���ܺ�������
//////////////////////////////////////////////////////////////////////////
void CMatrix::ScenseShow(char* title/* = */)
{
	//std::cout.width(4);
	std::cout<<"----------------------"<<title<<"--------------------------"<<std::endl;
	for(int i=0;i<This.mRow;i++)
	{
		for(int j=0;j<This.mCol;j++)
			std::cout<<std::setw(10)<<This.mElement[i*mCol+j]<<" ";
		std::cout<<std::endl;
	}
}
CMatrix CMatrix::getColAsCMatrix(int index)
{
	CMatrix temp(This.mRow,1);
	for(int i=0;i<This.mRow;i++)
		temp.mElement[i]=This(i,index);
	return temp;
}

CVector CMatrix::getColAsCVector(int index)
{
	CVector temp(This.mRow);
	for(int i=0;i<This.mRow;i++)
		temp[i]=(*this)(i,index);
	return temp;
}

CMatrix CMatrix::getRowAsCMatrix(int index)
{
	CMatrix temp(1,This.mCol);
	for(int i=0;i<This.mCol;i++)
		temp.mElement[i]=This(index,i);
	return temp;
}

CVector CMatrix::getRowAsCVector(int index)
{
	CVector temp(This.mCol);
	for(int i=0;i<This.mRow;i++)
		temp[i]=This(index,i);
	return temp;

}

bool CMatrix::AddCol(int index,double* values, int length)
{
	if(length!=This.mRow)
		return false;

	int j=0,k=0;
	This.mCol++;

	double* temppoint=new double[This.mRow*This.mCol];
	for(int i=0;i<This.mRow*This.mCol;i++)
		temppoint[i]=(i%This.mCol==index)?values[j++]:This.mElement[k++];
	
	delete[] This.mElement;
	This.mElement=new double[This.mRow*This.mCol];
	
	for(int i=0;i<This.mRow*This.mCol;i++)
		This.mElement[i]=temppoint[i];

	return true;
}
bool CMatrix::AddCol(int index,CMatrix matrix)
{
	int length=matrix.mCol*matrix.mRow;
	double* temp=new double[length];
	for(int i=0;i<length;i++)
		temp[i]=matrix.mElement[i];

	return CMatrix::AddCol(index,temp,length);
}
bool CMatrix::AddRow(int index,double* values, int length)
{
	if(length!=This.mCol)
		return false;
	double* temppoint=new double[(This.mRow+1)*This.mCol];

	int k=0;
	for(int i=0;i<This.mCol*(This.mRow+1);i++)
		if(i<index*mCol)
			temppoint[i]=This.mElement[i];
		else if(i>=index*mCol&&i<(index+1)*mCol)
			temppoint[i]=values[k++];
		else
			temppoint[i]=This.mElement[i-length];

	This.mRow++;

	delete[] This.mElement;
	This.mElement=new double[This.mRow*This.mCol];
	
	for(int i=0;i<This.mRow*(This.mCol);i++)
		This.mElement[i]=temppoint[i];

	return true;
}

bool CMatrix::AddRow(int index,CMatrix matrix)
{
	int length=matrix.mCol*matrix.mRow;
	double* temp=new double[length];
	for(int i=0;i<length;i++)
		temp[i]=matrix.mElement[i];

	return CMatrix::AddRow(index,temp,length);
}
int CMatrix::getColCount()
{
	return This.mCol;
}

int CMatrix::getRowCount()
{
	return This.mRow;
}

CMatrix CMatrix::Transposition()
{
	CMatrix temp(This.mCol,This.mRow);
		for(int i=0;i<This.mRow;i++)
			for(int j=0;j<This.mCol;j++)
			{
				temp(j,i)=This(i,j);
			}
	return temp;
}

bool CMatrix::setRow(int index,double* values)
{
	if(index<0||index>This.mRow)
		return false;

	int k=0;
	for(int i=index*mCol;i<(index+1)*mCol;i++)
		mElement[i]=values[k++];

	return true;
}

bool CMatrix::setRow(int index,CMatrix matrix)
{
	int length=matrix.mCol*matrix.mRow;
	double* temp=new double[length];
	for(int i=0;i<length;i++)
		temp[i]=matrix.mElement[i];

	return setRow(index,temp);
}

bool CMatrix::setCol(int index,double* values)
{
	if(index<0||index>This.mCol)
		return false;

	int k=0;
	for(int i=index;i<This.mCol*This.mRow;i+=This.mCol)
		mElement[i]=values[k++];
		
		return true;
}

bool CMatrix::setCol(int index,CMatrix matrix)
{
	int length=matrix.mCol*matrix.mRow;
	double* temp=new double[length];
	for(int i=0;i<length;i++)
		temp[i]=matrix.mElement[i];

	return setCol(index,temp);
}

CMatrix CMatrix::RemoveRow(int index)
{
	double* temppoint=new double[This.mCol*(This.mRow-1)];
	CMatrix result(1,mCol);
	int j=0;

	for(int i=0;i<This.mCol*This.mRow;i++)
	{
		if(i<index*mCol)
			temppoint[i]=mElement[i];
		else if(i>=index*mCol&&i<(index+1)*mCol)
			{result.mElement[j++]=mElement[i];}
		else
			temppoint[i-mCol]=mElement[i];
	}

	This.mRow--;

	mElement =new double[This.mRow*This.mCol];
	for(int i=0;i<This.mRow*This.mCol;i++)
	{
		mElement[i]=temppoint[i];
	}

	return result;
}

CMatrix CMatrix::RemoveCol(int index)
{
	double* temppoint=new double[(This.mCol-1)*This.mRow];
	CMatrix result(mRow,1);
	int k=0;

	for(int i=0;i<This.mRow;i++)
		for(int j=0;j<This.mCol;j++)
		{
			if(j!=index)
				temppoint[k++]=This(i,j);
		}

	This.mCol--;

	mElement =new double[This.mRow*This.mCol];
	for(int i=0;i<This.mRow*This.mCol;i++)
	{
		mElement[i]=temppoint[i];
	}
	return result;
}

bool CMatrix::LU_Decomposition(CMatrix& LMatrix,CMatrix& UMatrix)
{
	if(This.mCol==This.mRow&&LMatrix.mCol==UMatrix.mCol&&LMatrix.mRow==UMatrix.mRow)
	{
		for(int j=0;j<This.mCol;j++)
		{
			for(int i=0;i<=j;i++)
			{
				double sum=0.0;
				for(int k=0;k<i;k++)
					sum+=LMatrix(i,k)*UMatrix(k,j);
				UMatrix(i,j)=This(i,j)-sum;
			}
			for(int i=j+1;i<This.mCol;i++)
			{
				double sum=0.0;
				for(int k=0;k<i;k++)
					sum+=LMatrix(i,k)*UMatrix(k,j);
				LMatrix(i,j)=(This(i,j)-sum)/UMatrix(j,j);
			}
		}
		return true;
	}
	else
		return false;
}

double CMatrix::Invert(void)
{
	if(This.mRow!=This.mCol)
		{
			throw MatrixNonsquareException(mRow,mCol);
		}

	int* rowindex=new int[This.mRow];//��¼��Ԫ�б�
	int* colindex=new int[This.mCol];//��¼��Ԫ�б�

	for(int k=0;k<This.mCol;k++)
		{
			double pivot=findpivot(rowindex[k],colindex[k],k);//1.ȷ����Ԫֵ��λ��
			
			if(fab(pivot)<0.0001f)
			{
				if(rowindex!=0) delete[] rowindex;
				if(colindex!=0) delete[] colindex;
				throw MatrixSingularException(rowindex[k],colindex[k]);//1.1�����쳣
			}

			if(rowindex[k]!=k)//1.2��λ�����Խ��ߵ�����
				Swaps(rowindex[k],k,true);//����_�н���
			if(colindex[k]!=k)//1.3��λ�����Խ��ߵ�����
				Swaps(colindex[k],k,false);//����_�н���

			//2.������Ԫ����
			This(k,k)=1.0/This(k,k);

			//3.1��Ԫ_��Ԫ������
			for(int i=0;i<This.mCol;i++)
			{
				if(i!=k)//��Ԫ������
					This(k,i)=This(k,i)*This(k,k);
			}
			//3.2��Ԫ_����Ԫ��
			for(int i=0;i<This.mRow;i++)
			{
				if(i!=k)//��Ԫ������
				{
					for(int j=0;j<This.mCol;j++)
					{
						if(j!=k)
							This(i,j)=This(i,j)-This(i,k)*This(k,j);
					}
				}
			}
			for(int i=0;i<This.mCol;i++)
			{
				if(i!=k)//��Ԫ������
					This(i,k)=-This(i,k)*This(k,k);
			}
		}
	//�ָ�
	for(int k=This.mRow-1;k>=0;k--)
	{
		if(colindex[k]!=k)
			Swaps(k,colindex[k],false);
		if(rowindex[k]!=k)
			Swaps(k,rowindex[k],true);
	}

	if(rowindex!=0) delete[] rowindex;
	if(colindex!=0) delete[] colindex;

	return 1;
}

double CMatrix::Invert(CMatrix& outMat)
{
	outMat=This;
	return outMat.Invert();
}




CMatrix CMatrix::Trim(double eps/* =0.000001 */)
{
	double length=This.mCol*This.mRow;
	for(int i=0;i<length;i++)
		This.mElement[i]=(fab(This.mElement[i])<eps)?0.0:This.mElement[i];
	return This;
}

CMatrix CMatrix::Slove(CMatrix coe,SolveMethod Type)
{
	if(coe.getRowCount()!=This.mRow)
		throw MatrixNonsquareException();

	CMatrix temp(This);
	if(Type==Guass_Jardan)
	{
		temp.Invert();
		return temp*coe;
	}
	else 
	{
		CMatrix L=CMatrix::EyeMatrix(This.mCol);
		CMatrix U=CMatrix::EyeMatrix(This.mCol);
		temp.LU_Decomposition(L,U);

		CMatrix y(This.mCol,1);
		y(0,0)=coe(0,0)/L(0,0);
		for(int i=1;i<This.mCol;i++)
		{
			double sum=0.0;
			for(int j=0;j<i;j++)
				sum+=L(i,j)*y(j,0);
			y(i,0)=(coe(i,0)-sum)/L(i,i);
		}
		CMatrix x(This.mCol,1);

		x(This.mCol-1,0)=y(This.mCol-1,0)/U(This.mCol-1,This.mCol-1);

		for(int i=This.mCol-2;i>=0;i--)
		{
		    double sum=0.0;
			for(int j=i+1;j<This.mCol;j++)
				sum+=U(i,j)*x(j,0);
			x(i,0)=(y(i,0)-sum)/U(i,i);
		}
		return x;
	}
}
double CMatrix::Trace()
{
	double sum=0.0;
	if(This.mCol!=This.mRow)
		throw MatrixNonsquareException(This.mCol,This.mRow);
	else
	{
		for(int i=0;This.mCol;i++)
			sum+=This.mElement[i*(This.mCol+1)];
	}
	return sum;
}
CMatrix CMatrix::Hadamard(CMatrix* mat)
{
	CMatrix temp=CMatrix(This.mRow,This.mCol);
	for(int i=0;i<This.mRow*This.mCol;i++)
	{
		temp.mElement[i]=This.mElement[i]*mat->mElement[i];
	}
	return temp;
}

double CMatrix::Det()
{
	CMatrix* temp=new CMatrix(This);
	int flag=1;
	double det=0.0;

	if((*temp).mRow!=(*temp).mCol)
		{
			throw MatrixNonsquareException(mRow,mCol);
		}

	int* rowindex=new int[This.mRow];//��¼��Ԫ�б�
	int* colindex=new int[This.mCol];//��¼��Ԫ�б�

	for(int k=0;k<This.mCol;k++)
		{
			double pivot=temp->findpivot(rowindex[k],colindex[k],k);//1.ȷ����Ԫֵ��λ��
			
			if(fab(pivot)<0.0001f)
			{
				if(rowindex!=0) delete[] rowindex;
				if(colindex!=0) delete[] colindex;
				throw MatrixSingularException(rowindex[k],colindex[k]);//1.1�����쳣
			}

			if(rowindex[k]!=k)//1.2��λ�����Խ��ߵ�����
			{
				flag=-flag;
				temp->Swaps(rowindex[k],k,true);//����_�н���
			}
			if(colindex[k]!=k)//1.3��λ�����Խ��ߵ�����
			{
				flag=-flag;
				temp->Swaps(colindex[k],k,false);//����_�н���
			}
			
			det*=This(k,k);

			//2.������Ԫ����
			(*temp)(k,k)=1.0/(*temp)(k,k);

			//3.1��Ԫ_��Ԫ������
			for(int i=0;i<(*temp).mCol;i++)
			{
				if(i!=k)//��Ԫ������
					(*temp)(k,i)=(*temp)(k,i)*(*temp)(k,k);
			}
			//3.2��Ԫ_����Ԫ��
			for(int i=0;i<(*temp).mRow;i++)
			{
				if(i!=k)//��Ԫ������
				{
					for(int j=0;j<(*temp).mCol;j++)
					{
						if(j!=k)
							(*temp)(i,j)=(*temp)(i,j)-(*temp)(i,k)*(*temp)(k,j);
					} 
				}
			}
			for(int i=0;i<(*temp).mCol;i++)
			{
				if(i!=k)//��Ԫ������
					(*temp)(i,k)=-(*temp)(i,k)*(*temp)(k,k);
			}
		}

	if(rowindex!=0) delete[] rowindex;
	if(colindex!=0) delete[] colindex;
	delete temp;

	return det*flag;
}

CMatrix CMatrix::Householder()
{
	CMatrix Q=CMatrix(this->mCol,this->mCol);
	CMatrix E(Q);
	CMatrix A(This);

	for(int k=0;k<this->mCol-2;k++)
	{
		double Alpha=0.0;
		for(int j=k+1;j<this->mRow;j++)
			Alpha+=A(j,k)*A(j,k);
		Alpha=sign(A(k+1,k))*sqrt(Alpha);
		
		CMatrix U=CMatrix(this->mCol,1);

		for(int i=0;i<U.mRow;i++)
		{
			if(i<=k)
				U(i,0)=0;
			else
				U(i,0)=A(i,k);
		}
		U(k+1,0)+=Alpha;
		double temp=2/(U.Transposition()*U)(0,0);
		CMatrix P(E-U*U.Transposition()*temp);
		Q=Q*P;
		A=P*A*P;
	}
	This.Trim();
	return A;
}

bool CMatrix::QR_Decomposition(CMatrix& Q,CMatrix& R)
{
	//////////////////////////////////////////////////////////////////////////
	//0 �㷨׼�������ݼ���
	//////////////////////////////////////////////////////////////////////////

	//0.1 ���õ�ǰ�������¹���R����
	//    ���ڱ任�����R��չ��
	//    ��ɱ仯��R����Ϊ��������
	R=CMatrix(This);
	//0.2 �Ϸ��Լ��飬�����������ڻ��������ʱ���ſɽ��к����ֽ�
	if(R.mRow<R.mCol)
		return false;
	//0.3 ׼��Q����ά��Ϊ��this->mRow��this->mRow������ʼ��Ϊ��λ��
	Q=CMatrix(this->mRow,this->mRow);
	//0.4 ȷ��ѭ������ length=min��mRow-1,mCol��
	int length=(R.mRow==R.mCol)?this->mRow-1:this->mCol;
	

	//////////////////////////////////////////////////////////////////////////
	//1 QR�ֽ�ʵ�ʲ���
	//////////////////////////////////////////////////////////////////////////
	for(int k=0;k<length;k++)
	{
		//1.1 ����Hk��
		//1.1.1 Ѱ��R���е�K�е���ֵ����ֵ��������u�б���
		double u=0.0;
		for(int i=k;i<R.mRow;i++)
		{
			if(fab(R(i,k))>u)
				u=fab(R(i,k));
		}
		//1.1.2 ����Alpha����
		double Alpha=0.0,t1=0.0;//t1Ϊ��ʱ����
		for(int i=k;i<this->mRow;i++)
		{
			t1=R(i,k)/u;
			Alpha+=t1*t1;
		}
		Alpha=-1*sign(R(k,k))*u*sqrt(Alpha);
		// ��Alpha������С��ֽ�ֹͣ
		if(fab(Alpha)<0.000001)
			return false;
		
		//1.1.3 ����С������Rho�����ڱ���u�� 
		u=sqrt(2*Alpha*(Alpha-R(k,k)));
		//1.1.4 ����Rho��Ϊ0ʱ������ȥ������ֹ���֡����㡱����
		if(u!=0)
		{
			//1.1.5 ���㳣��Uk�����ڱ���R(k,k)��
			R(k,k)=(R(k,k)-Alpha)/u;
			//1.1.6 ���㳣��Ui�����ڱ���R(i,k)�У�i��ȡֵ��ΧΪ[k+1,R.mRow)
			for(int i=k+1;i<R.mRow;i++)
			{
				R(i,k)/=u;
			}
			//1.2 ��Hk���Q��
			for(int j=0;j<R.mRow;j++)
			{
				t1=0.0;
				for(int l=k;l<R.mRow;l++)
					t1+=(R(l,k)*Q(l,j));
				for(int i=k;i<R.mRow;i++)
					Q(i,j)=Q(i,j)-2*t1*R(i,k);
			}
			//1.2 ��Hk���A��
			for(int j=k+1;j<R.mCol;j++)
			{
				t1=0.0;
				for(int l=k;l<R.mRow;l++)
					t1+=(R(l,k)*R(l,j));
				for(int i=k;i<R.mRow;i++)
					R(i,j)=R(i,j)-2*t1*R(i,k);
			}
			R(k,k)=Alpha;
			//1.2.1 R��������ǲ�����0
			for(int i=k+1;i<R.mRow;i++)
				(R(i,k)=0.0);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//2 ��β����
	//////////////////////////////////////////////////////////////////////////
	Q=Q.Transposition();
	return true;
}

int CMatrix::Rank()
{

	CMatrix* temp=new CMatrix(This);
	int reuslt=0;
	int rowindex;//��¼��Ԫ�б�
	int colindex;//��¼��Ԫ�б�

	for(int k=0;k<this->mCol;k++)
		{
			double pivot=temp->findpivot(rowindex,colindex,k);//1.ȷ����Ԫֵ��λ��
			
			if(fab(pivot)>0.0001f)//��Ԫ��Ϊ0
			{
				if(rowindex!=k)//1.2��λ�����Խ��ߵ�����
				{
				
					temp->Swaps(rowindex,k,true);//����_�н���
				}
				if(colindex!=k)//1.3��λ�����Խ��ߵ�����
				{
					temp->Swaps(colindex,k,false);//����_�н���
				}
				//������1
				reuslt++;

				//2.������Ԫ����
				(*temp)(k,k)=1.0/(*temp)(k,k);

				//3.1��Ԫ_��Ԫ������
				for(int i=0;i<(*temp).mCol;i++)
				{
					if(i!=k)//��Ԫ������
						(*temp)(k,i)=(*temp)(k,i)*(*temp)(k,k);
				}
				//3.2��Ԫ_����Ԫ��
				for(int i=0;i<(*temp).mRow;i++)
				{
					if(i!=k)//��Ԫ������
					{
						for(int j=0;j<(*temp).mCol;j++)
						{
							if(j!=k)
								(*temp)(i,j)=(*temp)(i,j)-(*temp)(i,k)*(*temp)(k,j);
						} 
					}
				}
				for(int i=0;i<(*temp).mCol;i++)
				{
					if(i!=k)//��Ԫ������
						(*temp)(i,k)=-(*temp)(i,k)*(*temp)(k,k);
				}
			}
			else//��ԪΪ0
			{
				break;
			}
		}
	delete temp;
	return reuslt;
}

CMatrix CMatrix::Convolution(CMatrix &nuclear,bool IgnoreBound/* =true */)
{
	CMatrix result(this->mRow-(nuclear.mRow/2)*2,this->mCol-(nuclear.mCol/2)*2);
	
	int index,k=0,count=nuclear.mRow*nuclear.mCol;
	double sum=0;
	for(int i=0;i<=this->mRow-nuclear.mRow;i++)
	{
		for (int j=0;j<=this->mCol-nuclear.mCol;j++)
		{
			index=i*this->mCol+j;
			sum=0;
			for (int p=0;p<nuclear.mRow;p++)
			{
				for(int q=0;q<nuclear.mCol;q++)
				{
					sum+=this->mElement[index+p*this->mCol+q]*nuclear(p,q);
				}
			}
			result.mElement[k++]=sum/count;	
		}
	}
	return result;
}


//////////////////////////////////////////////////////////////////////////
//��������ز���
//////////////////////////////////////////////////////////////////////////
inline double& CMatrix::operator()(int i,int j)
{
	return mElement[i*mCol+j];
}

CMatrix CMatrix::operator+(CMatrix mat)
{
	CMatrix temp=CMatrix(mat.mRow,mat.mCol);
	for(int i=0;i<mat.mRow*mat.mCol;i++)
		temp.mElement[i]=This.mElement[i]+mat.mElement[i];

	return temp;
}

CMatrix CMatrix::operator-(CMatrix mat)
{
	CMatrix temp=CMatrix(mat.mRow,mat.mCol);
	for(int i=0;i<mat.mRow*mat.mCol;i++)
		temp.mElement[i]=This.mElement[i]-mat.mElement[i];
	return temp;
}

CMatrix& CMatrix::operator=(CMatrix matrix)
{
	if(&matrix!=this)
	{
		delete[] This.mElement;
	
		mElement=new double[matrix.mCol*matrix.mRow];
		for(int i=0;i<matrix.mCol*matrix.mRow;i++)
			This.mElement[i]=matrix.mElement[i];
	
		This.mCol=matrix.mCol;
		This.mRow=matrix.mRow;
	}
	return *this;
}

CMatrix CMatrix::operator* (double number)
{
	CMatrix temp(This);
	for(int i=0;i<This.mCol*This.mRow;i++)
		temp.mElement[i]=number*This.mElement[i];
	return temp;
}

CMatrix CMatrix::operator* (CMatrix matrix)
{
	CMatrix temp(mRow,matrix.mCol);

		int i,j,k;
		double sum; 
		int ct=0,cm=0,cw=0;//Ϊ*this, m��w�����α�,���趨��ʼλ��Ϊ(1,1)

	   //�����е�i��j����w(i,j)
	   for(i=1;i<=mRow;i++)
	   {
		   //���������ĵ�i ��  
		   for(j=1;j<=matrix.mCol;j++)
			{
				 //����w(i,j)�ĵ�һ��
				 sum=mElement[ct]*matrix.mElement[cm];//�ۼ�������
				 for(k=2;k<=mCol;k++)
				 {
				   ct++;//ָ��*this��i�е���һ��Ԫ��
				   cm+=matrix.mCol; // ָ��m �ĵ�j �е���һ����
				   sum+=mElement[ct]*matrix.mElement[cm];
				  }
				 temp.mElement[cw++]=sum; //����w(i,j)
				 //���µ��������׺���һ��
				 ct-=mCol-1;
				 cm=j;
			 }
			 //���µ�������һ�е����׺͵�һ��
			 ct+=mCol;
			 cm=0;
		  }
		return temp;
}

CMatrix CMatrix::operator^(int power)
{
	if(This.mCol!=This.mRow)
		throw MatrixNonsquareException(This.mCol,This.mRow);

	CMatrix temp(This);

	for(int i=0;i<power;i++)
		temp=temp*(This);

	return temp;
}
//////////////////////////////////////////////////////////////////////////
//��̬����
//////////////////////////////////////////////////////////////////////////
CMatrix CMatrix::ZeroMatrix(int n)
{
	return CMatrix::DiagMatrix(n,0.0);
}

CMatrix CMatrix::DiagMatrix(int n,double values)
{
	//ѭ���ڲ����Ż�������On2�ĳ���
	CMatrix temp(n,n);
	for (int i=0;i<temp.mRow;i++)
	{
		for(int j=0;j<temp.mCol;j++)
			if(i==j)
				temp(i,j)=values;
	}
	return temp;
}
CMatrix CMatrix::DiagMatrix(int n,double* values)
{
	//ѭ���ڲ����Ż�������On2�ĳ���
	CMatrix temp(n,n);
	int k=0;
	for (int i=0;i<temp.mRow;i++)
	{
		for(int j=0;j<temp.mCol;j++)
			if(i==j)
				temp(i,j)=values[k++];
	}
	return temp;
}
CMatrix CMatrix::EyeMatrix(int n)
{
	return CMatrix::DiagMatrix(n,1);
}

CMatrix CMatrix::ZeroMatrix(int m,int n)
{

	CMatrix temp(m,n);
	for(int i=0;i<m*n;i++)
		temp.mElement[i]=0;
	return temp;
}

CMatrix CMatrix::CreateByVector(CVector &vec)
{
	CMatrix temp(vec.getLength(),1);
	for(int i=0;i<vec.getLength();i++)
		temp.mElement[i]=vec[i];

	return vec.getDirection()? temp:temp.Transposition();
}

CMatrix CMatrix::S_Invert(CMatrix &mat)
{
	CMatrix temp(mat);
	temp.Invert();
	return temp;
}

CMatrix CMatrix::S_Hadamard(CMatrix &mat1,CMatrix &mat2)
{
	return mat1.Hadamard(&mat2);
}

CMatrix CMatrix::S_Transposition(CMatrix &mat1)
{
	return mat1.Transposition();
}

CMatrix CMatrix::S_Householder(CMatrix &mat1)
{
	return mat1.Householder();
}

//////////////////////////////////////////////////////////////////////////
//�ڲ���������
//////////////////////////////////////////////////////////////////////////////

double CMatrix::findpivot(int &i,int &j,int index)
{
	double pivot=0.001,temp;;
	for(int p=index;p<This.mRow;p++)
		for(int q=index;q<This.mCol;q++)
		{
			temp=(fab(This(p,q)));
			if(temp>pivot)
			{
				i=p;
				j=p;
				pivot=temp;
			}
		}
	return pivot;
}

void CMatrix::Swaps(int from,int to,bool IsRow/* =false */)
{
	if(IsRow)
	{
		for(int i=0;i<This.mCol;i++)
			swap(This(from,i),This(to,i));
	}
	else
	{
		for(int i=0;i<This.mRow;i++)
			swap(This(i,from),This(i,to));
	}
}

int CMatrix::sign(double e,double eps/* =0.000001 */)
{
	if(fab(e)<eps)
		return 1;
	else if(e<0)
		return -1;
	else 
		return 1;
}