#pragma once

#include <direct.h>
#include <string>
#include <fstream>

/*
*classname: BaseOuterListener
*brief:ͳһ����Ľӿ�
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
*brief:ͳһ����Ľӿ�
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
 *brief:�������c++�ļ�����Ĺ�����
 *author: Administrator
 *Date: February 2014
 */
 class FileUtils
{

	public:
		//************************************
		// Method:    IsExist
		// illustration_name:
		// illustration_fuction:����ָ��·�����ļ��Ƿ����
		// Parameter: std::string fullpath �������ָ��·��
		// Returns:   bool �����򷵻�ture
		// Other: �ļ�·��Ӧ����ȷ
		//************************************
		static bool IsExist(std::string fullpath);
		//************************************************************************
		// Method:    SplitFullPath
		// illustration_name:�ָ�ȫ·��
		// illustration_fuction:���ļ��ľ���·���ֽ�Ϊ��·�����ļ�������ʽ
		// Parameter: std::string fullpath ���ֽ��ȫ·������
		// Parameter: std::string & out_filepath �������������ڴ洢�ֽ����ļ�·��
		// Parameter: std::string & out_filename �������������ڴ洢�ֽ����ļ�����
		// Returns:   bool �ֽ�ɹ��򷵻�ture
		// Other: �ļ�·��Ӧ����ȷ
		//************************************************************************
		static bool SplitFullPath(std::string fullpath,std::string &out_filepath,std::string &out_filename);
		//************************************************************************
		//*�ļ��򿪷�ʽ��ö����
		//*Maintain:ͬ��ʱ���������ļ������������ļ�Ϊ(1)
		//*Override:ͬ��ʱ������ԭ�ļ�
		//*Append��ͬ��ʱ��׷�ӵ��ļ���β��
		//************************************************************************
		static enum openmode{Maintain=1,Override,Append};
	
	public:
		FileUtils(void);
		//************************************
		// Method:    FileUtils
		// illustration_name:���캯��
		// illustration_fuction:ͨ���ļ�·�����ļ�������
		// Parameter: std::string path ��\����β���ļ�·��
		// Parameter: std::string name  �����ļ���׺���ļ���
		// Other: ��
		//************************************
		FileUtils(std::string path,std::string name);
		//************************************
		// Method:    FileUtils
		// illustration_name: ���캯��
		// illustration_fuction:ͨ���ļ�ȫ·������
		// Parameter: std::string fullfilepath �Ϸ����ļ�·��
		//************************************
		FileUtils(std::string fullfilepath);
		~FileUtils(void);
		
	private:
		//�ļ�·��
		std::string mFilepath;
		//�ļ�����
		std::string mFilename;
		//�ļ���չ��
		std::string mExtension;
		//����������ļ���
		std::ofstream out;
		//����������ļ���
		std::ifstream input;
	
	private:
		//************************************
		// Method:    CombinePath
		// illustration_name:����ļ�ȫ·��
		// illustration_fuction:���ļ�·�����ļ������Լ���չ����ϳɺϷ����ļ�·��
		// Returns:   std::string �ļ���ȫ·��
		// Other: 
		//************************************
		std::string CombinePath();
		//************************************
		// Method:    CombinePath
		// illustration_name:����ļ�ȫ·��
		// illustration_fuction:���ļ�·�����ļ������Լ���չ����ϳɺϷ����ļ�·��
		// Parameter: int i ͬ������ʱ�ĺ�׺����
		// Returns:   std::string �ļ�ȫ·��
		// Other: 
		//************************************
		std::string CombinePath(int i);

	public:
		//************************************
		// Method:    IsExist
		// illustration_name:�����ļ��Ƿ����
		// illustration_fuction:
		// Returns:   bool ���ļ������򷵻�true
		// Other: 
		//************************************
		bool IsExist();
		//************************************
		// Method:    CreateOrOpenFile
		// illustration_name:�򿪻򴴽��ļ�
		// illustration_fuction:�Դ�������ķ�ʽ�򿪻򴴽�һ���ļ�
		// Parameter: openmode mode �ļ�ͬ����ͻ�Ľ��������Ĭ��ͬ������
		// Returns:   bool ���򿪳ɹ��򷵻�true
		// Other: 
		//************************************
		bool CreateOrOpenFile_ForWrite(FileUtils::openmode mode=Maintain);
		//************************************
		// Method:    OpenFile
		// illustration_name:���ļ�
		// illustration_fuction: ��ָ����·���µ��ļ�
		// Returns:   bool ���򿪳ɹ��򷵻�true
		// Other:  �˷�ʽ���ᴴ���µ��ļ�
		//************************************
		bool OpenFile_ForRead();
		//************************************
		// Method:    Close
		// illustration_name:�ر�������
		// illustration_fuction:
		// Returns:   void
		//************************************
		void Close();
		//************************************
		// Method:    Print
		// illustration_name: ��ӡ����
		// illustration_fuction: ����ָ���ĺ���ָ����ָ��ĺ������д�ӡ
		// Parameter: * printlistenr ָ��bool (*printlistenr)(std::ofstream &out)�����ĺ���ָ��
		// ���У�std::ofstream & out�ɵ�ǰ�����ṩ�Ŀ������������
		// Returns:   bool ����ɹ��򷵻�true
		// Other: 
		//************************************
		bool Print(bool (*printlistenr)(std::ofstream &out));
		//************************************
		// Method:    Print
		// illustration_name:��ӡ����
		// illustration_fuction:����ָ��������(�ӿ�)�еĴ�ӡ�������д�ӡ
		// Parameter: BaseOuterListener * listener BaseOuterListener�����������ָ��
		// Returns:   bool ����ɹ��򷵻�true
		// Other: 
		//************************************
		bool Print(BaseOuterListener* listener);
		//************************************
		// Method:    Scan
		// illustration_name:���뺯��
		// illustration_fuction:����ָ��������(�ӿ�)�е����뺯����������
		// Parameter: BaseInputListener * listener BaseInputListener�����������ָ��
		// Returns:   bool ����ɹ��򷵻�true
		// Other: 
		//************************************
		bool Scan(BaseInputListener* listener);
		//************************************
		// Method:    FilePath
		// illustration_name: Getter
		// illustration_fuction: ��ȡ�ļ�·��
		// Returns:   std::string �ļ�·��
		//************************************
		std::string FilePath();
		//************************************
		// Method:    FileName
		// illustration_name: Getter
		// illustration_fuction:��ȡ�ļ�����
		// Returns:   std::string �ļ���չ��
		// Other: 
		//************************************
		std::string FileName();
		//************************************
		// Method:    FileExtension
		// illustration_name: Getter
		// illustration_fuction: ��ȡ�ļ���չ��
		// Returns:   std::string �ļ���չ��
		// Other: 
		//************************************
		std::string FileExtension();
};

