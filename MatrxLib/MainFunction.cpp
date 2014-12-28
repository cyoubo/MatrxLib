#include "Matrix.h"
#include "FileUtils/FileUtils.h"
#include "MatrixFileUtils.h"
int main()
{
	////double p[]={5,1,-3,1,6,1,-3,1,7};
	////double p[]={6.6,-3.7,0,-3.7,9.5,-3.3,0,-3.3,7.3};
	////double q[]={-85.1,38.9,46.2};
	////QR分解使用测试数据
	////double p[]={0,3,1,0,4,-2,2,1,1};
	////double p[]={1,1,-1,2,1,0,1,-1,0,-1,2,1};
	////rank 测试数据
	////double p[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	////Hessenberg上三角化测试数据
	////double p[]={1,6,-3,-1,7,8,-15,18,5,4,-2,11,9,15,20,-13,2,21,30,-6,17,22,-5,3,6};
	////double p[]={-4,-3,-7,2,3,2,4,2,7};
	//double p[]={-3,-5,-1,13,13,1,-5,-5,1};

	//CMatrix mat1=CMatrix(p,3,3);
	//CMatrix mat2(mat1);
	//mat1.ScenseShow("organ data");
	////CMatrix R=CMatrix::DiagMatrix(1,1);
	////CMatrix Q=CMatrix::DiagMatrix(1,1);
	//mat1.Householder();
	////mat2.Hessenberg();
	////(Q*R).ScenseShow("QR in Householder");
	////mat1.ScenseShow("oraga data in main ");
	////mat1.ScenseShow("oraga in main");
	////mat1.Rank();
	////mat1.Trim();
	//mat1.ScenseShow("mat 1 result in main");
	//mat2.ScenseShow("mat 2 result in main");

	CMatrix mat1=CMatrix(40000,3);
	CMatrix mat2=CMatrix(1,3);
	//mat1.ScenseShow("mat1");
	//mat1.Convolution(mat2);
	FileUtils fileutils("G:\\Test1.csv");
	//bool result=fileutils.CreateOrOpenFile_ForWrite(FileUtils::openmode::Override);
	MatrixFileUtils t(mat1);
	//fileutils.Print(&t);
	bool r=fileutils.OpenFile_ForRead();
	fileutils.Scan(&t);
	t.getCMatrix().ScenseShow("eeeee");

}