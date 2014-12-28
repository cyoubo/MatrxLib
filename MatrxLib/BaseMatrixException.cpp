#include "BaseMatrixException.h"
BaseMatrixException::BaseMatrixException(int r,int c)
{
	this->mCol=c;
	this->mRow=r;
}

MatrixSingularException::MatrixSingularException(int r,int c)
	:BaseMatrixException(r,c)
{
	this->ErrorCode=Singular;
}
MatrixSingularException::MatrixSingularException(MatrixSingularException &Except)
{
	this->ErrorCode=Except.ErrorCode;
}
std::string MatrixSingularException::getExceptionMesssage()
{
	std::ostringstream temp;
	temp<<"provit is 0 location is c"<<mRow<<","<<mCol<<")"<<std::endl;
	return temp.str();
}
MatrixNonsquareException::MatrixNonsquareException(int r,int c)
	:BaseMatrixException(r,c)
{
	this->ErrorCode=Nonsquare;
}
MatrixNonsquareException::MatrixNonsquareException(MatrixNonsquareException &Except)
{
	this->ErrorCode=Except.ErrorCode;
}
std::string MatrixNonsquareException::getExceptionMesssage()
{
	std::ostringstream temp;
	temp<<"the matrix dim is ("<<mRow<<"*"<<mCol<<"),is not a square"<<std::endl;
	return temp.str();
}
MatrixNoMethodException::MatrixNoMethodException(int r,int c,std::string MethodName)
	:BaseMatrixException(r,c)
{
	this->ErrorCode=Nonsquare;
	this->MethodName=MethodName;
}
MatrixNoMethodException::MatrixNoMethodException(MatrixNoMethodException &Except)
{
	this->ErrorCode=Nonsquare;
	this->MethodName=Except.MethodName;
}
std::string MatrixNoMethodException::getExceptionMesssage()
{
	std::ostringstream temp;
	temp<<"the method  is ("<<this->MethodName<<") is not be found"<<std::endl;
	return temp.str();
}

MatrixSizeException::MatrixSizeException(MatrixSizeException &Except)
{
	this->ErrorCode=Except.ErrorCode;
	this->SizeDescribetion=Except.SizeDescribetion;
}

MatrixSizeException::MatrixSizeException(std::string message)
{
	this->ErrorCode=SizeError;
	this->SizeDescribetion=message;
}

std::string MatrixSizeException::getExceptionMesssage()
{
	return this->SizeDescribetion;
}


