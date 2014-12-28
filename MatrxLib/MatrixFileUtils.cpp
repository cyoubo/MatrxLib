#include "MatrixFileUtils.h"


MatrixFileUtils::MatrixFileUtils(void)
{
}

MatrixFileUtils::MatrixFileUtils(CMatrix &mat,FileType ftype/* =CSV */)
{
	this->mat=mat;
	this->ftype=ftype;
}

MatrixFileUtils::~MatrixFileUtils(void)
{
}

void MatrixFileUtils::setCMatrix(CMatrix &mat)
{
	this->mat=mat;
}

void MatrixFileUtils::setFileType(FileType type)
{
	this->ftype=type;
}

bool MatrixFileUtils::print(std::ofstream &out)
{
	out<<"size:"<<mat.getRowCount()<<"-"<<mat.getColCount()<<std::endl;

	std::string flag="";
	
	switch(ftype)
	{
		case CSV :flag="," ;break;
		case DAT :flag=" " ;break;
		case TXT :flag="|" ;break;
	}


	for(int i=0;i<mat.getRowCount();i++)
	{
		for(int j=0;j<mat.getColCount();j++)
		{	
			if(j<mat.getColCount()-1)
				out<<mat.operator()(i,j)<<flag;
			else
				out<<mat.operator()(i,j);
		}
		out<<std::endl;
	}

	out.close();
	return true;
}

bool MatrixFileUtils::scan(std::ifstream &input)
{
		char temp;int row,col;
		while(input.get(temp) &&temp!=':');	
		input>>row;
		input.ignore(1,'-');
		input>>col;
		
		//构建结果矩阵
		this->mat=CMatrix(row,col);
		//确定分隔符
		char flag= ' ';
		switch(ftype)
		{
			case CSV :flag=',' ;break;
			case DAT :flag=' ' ;break;
			case TXT :flag='|' ;break;
	    }
		//数据读入
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				input>>mat(i,j);//读入数据
				input.ignore(1,flag);//忽略一个分隔符
			}
		}
		//this->mat.ScenseShow("in list");
		return true;
}
