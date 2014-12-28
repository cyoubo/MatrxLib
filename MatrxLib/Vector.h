#pragma once

#include "CommonHeader.h"
//������ǰ������˵��//////////////////////////////////////////////////////
class CMatrix;
//////////////////////////////////////////////////////////////////////////\


/************************************************************************/
/* CVector ������
/************************************************************************/
class CVector
{
	protected:
		double *mElement;//Ԫ��ָ��
		int length;//�������� 
		bool IsColumn;//�Ƿ�δ������
	public:
		//////////////////////////////////////////////////////////////////////////
		//���췽������
		//////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    CVector
		// illustration_name: ���캯��
		// illustration_fuction: Ĭ�Ϲ��캯�������쵥λ������
		// Parameter: int count ָ�������ĳ��ȣ� 
		//************************************
		CVector(int count=3);
		//************************************
		// Method:    CVector
		// illustration_name: ���캯��
		// illustration_fuction: ָ�����ݣ������Լ�����������
		// Parameter: double * p �������ݵ�double����
		// Parameter: int count �����ĳ���
		// Parameter: bool isCol ָ����������trueΪ������
		//************************************
		CVector(double *p,int count,bool isCol=true);
		//************************************
		// Method:    CVector
		// illustration_name: �������캯��
		// Parameter: CVector & c ����������������
		//************************************
		CVector(CVector &c);
		//************************************
		// Method:    ~CVector
		// illustration_name: ��������
		// illustration_fuction: ����ڴ�ռ���ͷ�
		//************************************
		~CVector(void);
		///////////////////////////////////////////////////////////////////////////////
		//���ܺ���
		///////////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    CrossProduct
		// illustration_name: �����Ĳ��
		// illustration_fuction: �������3ά�������������
		// Parameter: CVector & vec ������
		// Returns:   CVector ����������
		// Other: �ð汾�����ܴ�����ά�����Ĳ��
		//************************************
		CVector CrossProduct(CVector &vec);
		//************************************
		// Method:    MatrixProduct
		// illustration_name: ���������
		// illustration_fuction: ���������*���������ָ�����ĳ˷�
		// Parameter: CVector & vec ���˵�������
		// Returns:   CMatrix �������
		// Other: Ҫ����������ά��һ�£������෴������ͬ������е������
		//************************************
		CMatrix MatrixProduct(CVector &vec);
		//************************************
		// Method:    Mod
		// illustration_name: ������ģ
		// Returns:   double ��ǰ������ģ��
		//************************************
		double Mod();
		//************************************
		// Method:    Normalize
		// illustration_name: �����Ĺ淶��
		// illustration_fuction: �Ե�ǰ�������й淶������
		// Returns:   void
		// Other:  �÷����޸ĵ�ǰ������
		//************************************
		void Normalize();
		//************************************
		// Method:    Transportation
		// illustration_name: ����ת��(����)
		// illustration_fuction: �ı����������з���
		// Returns:   void 
		// Other: �÷����޸ĵ�ǰ������
		//************************************
		void Transportation()
			{this->IsColumn=!this->IsColumn;}
		//************************************
		// Method:    getDirection
		// illustration_name: ��õ�ǰ�������з���������
		// Returns:   bool trueΪ����������Ϊ������
		//************************************
		bool getDirection()
			{return this->IsColumn;}
		//************************************
		// Method:    getLength
		// illustration_name: ��ȡ��ǰ�����ĳ���
		// Returns:   int �����ĳ���
		//************************************
		int getLength()
			{return this->length;}
		///////////////////////////////////////////////////////////////////////////////
		//��̬����
		///////////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    GetDistance
		// illustration_name: �������������
		// Parameter: CVector & vec1 �������
		// Parameter: CVector & vec2 �յ�����
		// Returns:   double ŷ�Ͼ���
		//************************************
		double static GetDistance(CVector &vec1,CVector &vec2); 
		//************************************
		// Method:    NormalizetoCVector
		// illustration_name: �����淶��
		// illustration_fuction:
		// Returns:   CVector �淶���������
		//************************************
		CVector static NormalizetoCVector();
		//************************************
		// Method:    CreateZeroVector
		// illustration_name: ����0����
		// illustration_fuction: ����ָ�����ȣ�����Ԫ�ؾ�Ϊ0��������
		// Parameter: int n �Զ�����
		// Returns:   CVector ������0����
		//************************************
		CVector CreateZeroVector(int n);
		///////////////////////////////////////////////////////////////////////////////
		//���������
		///////////////////////////////////////////////////////////////////////////////
		CVector& operator=(CVector &c);
		//************************************
		// Method:    operator+
		// illustration_name: �������
		// illustration_fuction:
		// Parameter: CVector & c ��������
		// Returns:   CVector �������
		// Other: ǰ��������������ά��Ӧһ�£�����������쳣
		//************************************
		CVector operator+(CVector &c);
		//************************************
		// Method:    operator-
		// illustration_name: ����ȡ��
		// illustration_fuction: ��������Ԫ�ؾ�ȡ��
		// Returns:   CVector ȡ���������
		// Other: �ĺ������޸ĸõ�ǰ������
		//************************************
		CVector operator-();
		//************************************
		// Method:    operator-
		// illustration_name: �������
		// illustration_fuction:
		// Parameter: CVector & c ��������
		// Returns:   CVector �������
		// Other: ǰ��������������ά��Ӧһ�£�����������쳣
		//************************************
		CVector operator-(CVector &c);
		//************************************
		// Method:    operator*
		// illustration_name: ���������ĳ˷�
		// Parameter: double num ������
		// Returns:   CVector �������
		// Other:  �ķ������޸ĵ�ǰ������
		//************************************
		CVector operator*(double num);
		//************************************
		// Method:    operator*
		// illustration_name: �����ĵ��
		// illustration_fuction: �����������ڻ�
		// Parameter: CVector & vec ��������
		// Returns:   double �ڻ�
		// Other: ǰ������������ά��Ӧ��һ��
		//************************************
		double operator*(CVector &vec);
		
		bool operator==(CVector &vec);
		//************************************
		// Method:    operator[]
		// illustration_name:����[]
		// illustration_fuction:���������ָ���±��Ԫ��
		// Parameter: int i ��0��ʼ��Ԫ���±�
		// Returns:   double& ���ص�Ԫ������
		//************************************
		double& operator[] (int i);


};

