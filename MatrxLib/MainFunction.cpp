#include "CommonHeader.h"
#include "MatrixFileUtils.h"
#include "FileUtils/FileUtils.h"
int main()
{
	//double p[]={1,1,1,1,1};

	CMatrix Mat_data=CMatrix(300,3);
	//CMatrix Mat_nuclear=CMatrix(p,5,1);
	FileUtils fileutils("F:\\cyoubo_lab_eo\\diff_nuclear\\Data1\\DataC.csv");
	MatrixFileUtils t(Mat_data);
	bool r=fileutils.OpenFile_ForRead();
	fileutils.Scan(&t);
	CMatrix src=t.getCMatrix().getColAsCMatrix(0);
	double* q=new double[src.getRowCount()];
	for(int i=0;i<src.getRowCount();i++)
		q[i]=(i+1);
	src.AddCol(0,q,src.getRowCount());
	////row1.ScenseShow("11");
	////(Mat_nuclear*(1.0/Mat_nuclear.sum())).ScenseShow("nuclear");
	//MatrixFileUtils t2(row1.Convolution(Mat_nuclear)*(1.0/Mat_nuclear.sum()));
	//FileUtils fileutils2("F:\\cyoubo_lab_eo\\diff_nuclear\\Data1\\fitter11111.csv");
	//fileutils2.CreateOrOpenFile_ForWrite(FileUtils::openmode::Override);
	//fileutils2.Print(&t2);
	//fileutils2.Close();

	//double q[]={1,2,3,4,6,5};
	////CMatrix src(q,3,2);
	CMatrix coe(1,2);
	src.ScenseShow("Src");
	double re=src.Fitt_StraightLine(coe);
	coe.ScenseShow("dee");
	std::cout<<"rmse is"<<re<<std::endl;
	std::cout<<"result"<<coe(0,0)*(src.getRowCount()/2)+coe(1,0)<<std::endl;
}