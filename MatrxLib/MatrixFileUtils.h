#pragma once

////////////////////////////////////////////////
//����ͷ�ļ�
////////////////////////////////////////////////
#include "CommonHeader.h"
////////////////////////////////////////////////
//������ǰ������˵��
////////////////////////////////////////////////
class CMatrix;
enum FileType {CSV,DAT,TXT};
////////////////////////////////////////////////
//MatrixFileUtils ������ʵ����BaseOuterListener��BaseInputListener�ɱ�FileUtilsʹ�õľ������������
////////////////////////////////////////////////
class MatrixFileUtils :
	public BaseOuterListener,public BaseInputListener
{ 
	/**************************************˽�г�Ա����****************************/
	private :
		CMatrix mat;//���ݾ���
		FileType ftype;//�ļ��������
	/**************************************���г�Ա����****************************/
	////////////////////////////////////////////////////////////////////////////////
	//���췽��
	////////////////////////////////////////////////////////////////////////////////
	public:
		MatrixFileUtils(void);
		//************************************
		// Method:    MatrixFileUtils
		// illustration_name: ���캯��
		// illustration_fuction: 
		// Parameter: CMatrix & mat ��������ô洢��������ݾ���
		// Parameter: FileType ftype �������ļ����ͣ�Ĭ��Ϊcsv
		//************************************
		MatrixFileUtils(CMatrix &mat,FileType ftype=CSV);
		~MatrixFileUtils(void);
	
	///////////////////////////////////////////////////////////////////////////////
	//������
	///////////////////////////////////////////////////////////////////////////////
		void setCMatrix(CMatrix &mat);
		void setFileType(FileType type);
		CMatrix getCMatrix() {return this->mat;};
	///////////////////////////////////////////////////////////////////////////////
	//���ܺ���
	///////////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    print
		// illustration_name: �������
		// illustration_fuction: �����ṩ��ofstream���� out���о������ݵ��ļ����
		// Parameter: std::ofstream & out ��FileUtils���󴴽��õ�ofstream����
		// Returns:   bool ����������򷵻�true���򷵻�false
		// Other: 
		//************************************
		bool print(std::ofstream &out);
		//************************************
		// Method:    scan
		// illustration_name: ���뺯��
		// illustration_fuction: �����ṩ��ifstream����input���о������ݵ��ļ�������
		// Parameter: std::ifstream & input ��FileUtils���󴴽��õ�ofstream����
		// Returns:   bool �����������򷵻�true���򷵻�false
		// Other: 
		//************************************
		bool scan(std::ifstream &input);

};

