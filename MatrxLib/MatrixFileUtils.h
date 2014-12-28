#pragma once

////////////////////////////////////////////////
//引用头文件
////////////////////////////////////////////////
#include "CommonHeader.h"
////////////////////////////////////////////////
//相关类的前置引用说明
////////////////////////////////////////////////
class CMatrix;
enum FileType {CSV,DAT,TXT};
////////////////////////////////////////////////
//MatrixFileUtils 描述：实现了BaseOuterListener与BaseInputListener可被FileUtils使用的矩阵输出输入类
////////////////////////////////////////////////
class MatrixFileUtils :
	public BaseOuterListener,public BaseInputListener
{ 
	/**************************************私有成员变量****************************/
	private :
		CMatrix mat;//数据矩阵
		FileType ftype;//文件输出类型
	/**************************************共有成员变量****************************/
	////////////////////////////////////////////////////////////////////////////////
	//构造方法
	////////////////////////////////////////////////////////////////////////////////
	public:
		MatrixFileUtils(void);
		//************************************
		// Method:    MatrixFileUtils
		// illustration_name: 构造函数
		// illustration_fuction: 
		// Parameter: CMatrix & mat 待输出或用存储输入的数据矩阵
		// Parameter: FileType ftype 操作的文件类型，默认为csv
		//************************************
		MatrixFileUtils(CMatrix &mat,FileType ftype=CSV);
		~MatrixFileUtils(void);
	
	///////////////////////////////////////////////////////////////////////////////
	//访问器
	///////////////////////////////////////////////////////////////////////////////
		void setCMatrix(CMatrix &mat);
		void setFileType(FileType type);
		CMatrix getCMatrix() {return this->mat;};
	///////////////////////////////////////////////////////////////////////////////
	//功能函数
	///////////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    print
		// illustration_name: 输出函数
		// illustration_fuction: 利用提供的ofstream对象 out进行矩阵数据的文件输出
		// Parameter: std::ofstream & out 由FileUtils对象创建好的ofstream对象
		// Returns:   bool 若输出正常则返回true否则返回false
		// Other: 
		//************************************
		bool print(std::ofstream &out);
		//************************************
		// Method:    scan
		// illustration_name: 输入函数
		// illustration_fuction: 利用提供的ifstream对象input进行矩阵数据的文件输输入
		// Parameter: std::ifstream & input 由FileUtils对象创建好的ofstream对象
		// Returns:   bool 若输入正常则返回true否则返回false
		// Other: 
		//************************************
		bool scan(std::ifstream &input);

};

