#pragma once

#include <direct.h>
#include <string>
#include <fstream>

/*
*classname: BaseOuterListener
*brief:统一输出的接口
*author: Administrator
*Date: February 2014
*/
class BaseOuterListener
{
	public:
		virtual bool print(std::ofstream &out)=0;
};
/*
*classname: BaseOuterListener
*brief:统一输出的接口
*author: Administrator
*Date: February 2014
*/
class BaseInputListener
{
	public:
		virtual bool scan(std::ifstream &input)=0;
};
 /*
 *classname: FileUtils
 *brief:用于完成c++文件输出的工具类
 *author: Administrator
 *Date: February 2014
 */
 class FileUtils
{

	public:
		//************************************
		// Method:    IsExist
		// illustration_name:
		// illustration_fuction:检验指定路径的文件是否存在
		// Parameter: std::string fullpath 待检验的指定路径
		// Returns:   bool 存在则返回ture
		// Other: 文件路径应当正确
		//************************************
		static bool IsExist(std::string fullpath);
		//************************************************************************
		// Method:    SplitFullPath
		// illustration_name:分割全路径
		// illustration_fuction:将文件的绝对路径分解为，路径与文件名的形式
		// Parameter: std::string fullpath 待分解的全路径数组
		// Parameter: std::string & out_filepath 传出参数，用于存储分解后的文件路径
		// Parameter: std::string & out_filename 传出参数，用于存储分解后的文件名称
		// Returns:   bool 分解成功则返回ture
		// Other: 文件路径应当正确
		//************************************************************************
		static bool SplitFullPath(std::string fullpath,std::string &out_filepath,std::string &out_filename);
		//************************************************************************
		//*文件打开方式的枚举类
		//*Maintain:同名时保留两个文件，并命名新文件为(1)
		//*Override:同名时，覆盖原文件
		//*Append：同名时，追加到文件结尾处
		//************************************************************************
		static enum openmode{Maintain=1,Override,Append};
	
	public:
		FileUtils(void);
		//************************************
		// Method:    FileUtils
		// illustration_name:构造函数
		// illustration_fuction:通过文件路径与文件名构造
		// Parameter: std::string path “\”结尾的文件路径
		// Parameter: std::string name  包含文件后缀的文件名
		// Other: 无
		//************************************
		FileUtils(std::string path,std::string name);
		//************************************
		// Method:    FileUtils
		// illustration_name: 构造函数
		// illustration_fuction:通过文件全路径构造
		// Parameter: std::string fullfilepath 合法的文件路径
		//************************************
		FileUtils(std::string fullfilepath);
		~FileUtils(void);
		
	private:
		//文件路径
		std::string mFilepath;
		//文件名称
		std::string mFilename;
		//文件扩展名
		std::string mExtension;
		//用于输出的文件流
		std::ofstream out;
		//用于输入的文件流
		std::ifstream input;
	
	private:
		//************************************
		// Method:    CombinePath
		// illustration_name:组合文件全路径
		// illustration_fuction:将文件路径，文件名称以及扩展名组合成合法的文件路径
		// Returns:   std::string 文件的全路径
		// Other: 
		//************************************
		std::string CombinePath();
		//************************************
		// Method:    CombinePath
		// illustration_name:组合文件全路径
		// illustration_fuction:将文件路径，文件名称以及扩展名组合成合法的文件路径
		// Parameter: int i 同名保留时的后缀序列
		// Returns:   std::string 文件全路径
		// Other: 
		//************************************
		std::string CombinePath(int i);

	public:
		//************************************
		// Method:    IsExist
		// illustration_name:检验文件是否存在
		// illustration_fuction:
		// Returns:   bool 若文件存在则返回true
		// Other: 
		//************************************
		bool IsExist();
		//************************************
		// Method:    CreateOrOpenFile
		// illustration_name:打开或创建文件
		// illustration_fuction:以打开流对象的方式打开或创建一个文件
		// Parameter: openmode mode 文件同名冲突的解决方法，默认同名保留
		// Returns:   bool 若打开成功则返回true
		// Other: 
		//************************************
		bool CreateOrOpenFile_ForWrite(FileUtils::openmode mode=Maintain);
		//************************************
		// Method:    OpenFile
		// illustration_name:打开文件
		// illustration_fuction: 打开指定的路径下的文件
		// Returns:   bool 若打开成功则返回true
		// Other:  此方式不会创建新的文件
		//************************************
		bool OpenFile_ForRead();
		//************************************
		// Method:    Close
		// illustration_name:关闭流对象
		// illustration_fuction:
		// Returns:   void
		//************************************
		void Close();
		//************************************
		// Method:    Print
		// illustration_name: 打印函数
		// illustration_fuction: 根据指定的函数指针所指向的函数进行打印
		// Parameter: * printlistenr 指向bool (*printlistenr)(std::ofstream &out)申明的函数指针
		// 其中，std::ofstream & out由当前对象提供的可以输出流对象
		// Returns:   bool 输出成功则返回true
		// Other: 
		//************************************
		bool Print(bool (*printlistenr)(std::ofstream &out));
		//************************************
		// Method:    Print
		// illustration_name:打印函数
		// illustration_fuction:根据指定抽象类(接口)中的打印函数进行打印
		// Parameter: BaseOuterListener * listener BaseOuterListener抽象类的子类指针
		// Returns:   bool 输出成功则返回true
		// Other: 
		//************************************
		bool Print(BaseOuterListener* listener);
		//************************************
		// Method:    Scan
		// illustration_name:输入函数
		// illustration_fuction:根据指定抽象类(接口)中的输入函数进行输入
		// Parameter: BaseInputListener * listener BaseInputListener抽象类的子类指针
		// Returns:   bool 输入成功则返回true
		// Other: 
		//************************************
		bool Scan(BaseInputListener* listener);
		//************************************
		// Method:    FilePath
		// illustration_name: Getter
		// illustration_fuction: 获取文件路径
		// Returns:   std::string 文件路径
		//************************************
		std::string FilePath();
		//************************************
		// Method:    FileName
		// illustration_name: Getter
		// illustration_fuction:获取文件名称
		// Returns:   std::string 文件扩展名
		// Other: 
		//************************************
		std::string FileName();
		//************************************
		// Method:    FileExtension
		// illustration_name: Getter
		// illustration_fuction: 获取文件扩展名
		// Returns:   std::string 文件扩展名
		// Other: 
		//************************************
		std::string FileExtension();
};

