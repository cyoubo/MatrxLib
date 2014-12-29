#include "Matrix.h"
#include "FileUtils/FileUtils.h"
#include "MatrixFileUtils.h"
int main()
{
	double p[]={1,1,1,1,1};

	CMatrix Mat_data=CMatrix(1000,3);
	CMatrix Mat_nuclear=CMatrix(p,5,1);
	FileUtils fileutils("F:\\cyoubo_lab_eo\\diff_nuclear\\Data1\\DataC.csv");
	MatrixFileUtils t(Mat_data);
	bool r=fileutils.OpenFile_ForRead();
	fileutils.Scan(&t);
	CMatrix row1=t.getCMatrix().getColAsCMatrix(0);
	//row1.ScenseShow("11");
	//(Mat_nuclear*(1.0/Mat_nuclear.sum())).ScenseShow("nuclear");
	MatrixFileUtils t2(row1.Convolution(Mat_nuclear)*(1.0/Mat_nuclear.sum()));
	FileUtils fileutils2("F:\\cyoubo_lab_eo\\diff_nuclear\\Data1\\fitter11111.csv");
	fileutils2.CreateOrOpenFile_ForWrite(FileUtils::openmode::Override);
	fileutils2.Print(&t2);
	fileutils2.Close();


}