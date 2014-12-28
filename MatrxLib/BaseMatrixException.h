#pragma once
/***
*�Զ�����������쳣�Ļ���
***/
#include "CommonHeader.h"

class BaseMatrixException
{
	protected:
		int ErrorCode;
		int mRow,mCol;
	public:
		BaseMatrixException(void){};
		BaseMatrixException(int r,int c);
		virtual std::string getExceptionMesssage()=0;
};
/***
*���������쳣��
***/
class MatrixSingularException : public BaseMatrixException
{
	public:
		MatrixSingularException(){};
		MatrixSingularException(int r,int c);
		MatrixSingularException(MatrixSingularException &Except);
		std::string getExceptionMesssage();
};

/***
*�Ƿ����쳣��
***/
class MatrixNonsquareException : public BaseMatrixException
{
	public:
		MatrixNonsquareException(){};
		MatrixNonsquareException(int r,int c);
		MatrixNonsquareException(MatrixNonsquareException &Except);
		std::string getExceptionMesssage();
};

/***
*�����쳣��
***/
class MatrixNoMethodException : public BaseMatrixException
{
	private:
		std::string MethodName;
	public:
		MatrixNoMethodException(){};
		MatrixNoMethodException(int r,int c,std::string MethodName);
		MatrixNoMethodException(MatrixNoMethodException &Except);
		std::string getExceptionMesssage();
};
/***
*����ߴ��쳣��
***/
class MatrixSizeException:public BaseMatrixException
{
	private:
		std::string SizeDescribetion;

	public:
		MatrixSizeException(){};
		MatrixSizeException(std::string message);
		MatrixSizeException(MatrixSizeException &Except);
		std::string getExceptionMesssage();

};

enum MatrixExceptionCode
{
	Singular=1,Nonsquare=2,NoMethod=3,SizeError
};