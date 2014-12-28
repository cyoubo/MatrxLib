 #pragma once

#include "CommonHeader.h"
/**
����ƽ�����ͳһ�ӿڣ������
*/
class AbstructAdjustment
{
	protected:
		int N;//�ܹ۲���
		int T;//��Ҫ�۲���
		//����ͱ���
		CMatrix* V;//����������
		CMatrix* Qvv;//������Э������
		double Rmse;//�����
		CMatrix* Lg;//�۲�ֵ����������
		//�����ͱ���
		CMatrix* P;//Ȩ��
		CMatrix* L;//�۲�ֵ����
		//��ʶ�������ڱ���Ƿ���й�����
		bool IsCalculated;
		//************************************
		// Method:    Calculate_Rmse
		// illustration_name: ���㵥λȨ�����
		// illustration_fuction: ����sqrt(VtPV)��Ҫ�󣬼��㵱ǰƽ�����ĵ�λȨ�����
		// Returns:   void ��¼����Rmse��Ա��
		// Other: �÷���Ϊ�ڲ�����
		//************************************
		void Calculate_Rmse();
	public:
		//////////////////////////////////////////////////////////////////////////
		//���췽������
		//////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    AbstructAdjustment
		// illustration_name: ���캯��
		// illustration_fuction: Ĭ�Ϲ��캯������ʵ�����в�����0ֵ��ʼ��
		// Parameter: void 
		//************************************
		AbstructAdjustment(void);
		//************************************
		// Method:    AbstructAdjustment
		// illustration_name: ���캯��
		// illustration_fuction: ָ���ܹ۲������Ҫ�۲������Ĺ���
		// Parameter: int n �۲�����
		// Parameter: int t ��Ҫ�۲���
		//************************************
		AbstructAdjustment(int n,int t);
		//************************************
		// Method:    AbstructAdjustment
		// illustration_name: ���캯��
		// illustration_fuction: ָ��Ȩ�󡢹۲�ֵ�������Ҫ�۲������й���
		// Parameter: CMatrix P Ȩ��
		// Parameter: CMatrix L �۲�ֵ����
		// Parameter: int t ��Ҫ�۲���
		//************************************
		AbstructAdjustment(CMatrix P,CMatrix L,int t);
		//************************************
		// Method:    ~AbstructAdjustment
		// illustration_name: ��������
		// illustration_fuction: ������ɵ�ǰ���������
		// Parameter: void
		//************************************
		~AbstructAdjustment(void);
		//////////////////////////////////////////////////////////////////////////
		//���ܺ�������
		//////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    getRmse
		// illustration_name: ��õ�λȨ�����
		// illustration_fuction: �ڡ���ɼ��㡱״̬�£���ȡ�������õĵ�λȨ�����
		// Returns:   double ��õĵ�λȨ�����
		// Other: ǰ������getCalCulateStatus()�ķ���ֵΪTure
		//************************************
		double getRmse();
		//************************************
		// Method:    getCorrectionMatrix
		// illustration_name: ��ø���������
		// illustration_fuction: �ڡ���ɼ��㡱״̬�£���ü������õĸ���������
		// Returns:   CMatrix ��t*1���ľ����ʾ�ĸ���������
		// Other: ǰ������getCalCulateStatus()�ķ���ֵΪTure
		//************************************
		CMatrix getCorrectionMatrix();
		//************************************
		// Method:    getPowerMatrix
		// illustration_name: �������Ȩ��
		// illustration_fuction: �������Ȩ��
		// Returns:   CMatrix ��n*n���ľ����ʾ��Ȩ��
		//************************************
		CMatrix getPowerMatrix();
		//************************************
		// Method:    getCorrectionCoFactorMatrix
		// illustration_name: ���Qvv
		// illustration_fuction: ��ü����ĸ�����Э������
		// Returns:   CMatrix ������Э������
		// Other: 
		//************************************
		CMatrix getCorrectionCoFactorMatrix();
		//************************************
		// Method:    getObservationMatrix
		// illustration_name: ��ù۲�ֵ����
		// illustration_fuction: 
		// Returns:   CMatrix �۲�ֵ����
		// Other: 
		//************************************
		CMatrix getObservationMatrix();
		//************************************
		// Method:    getObservationCorrectionMatrix
		// illustration_name: ��ȡ������۲�ֵ
		// illustration_fuction: 
		// Parameter: CMatrix * ObservationMatrix ����ָ����ʼ�Ĺ۲�ֵʱ��Ĭ��ʹ�õ�ǰ��������Ĺ۲�ֵ
		// Returns:   CMatrix ������Ĺ۲�ֵ
		// Other: 
		//************************************
		CMatrix getObservationCorrectionMatrix(CMatrix *ObservationMatrix=NULL);
		//************************************
		// Method:    getCalCulateStatus
		// illustration_name: ��á���ɼ��㡱״̬
		// illustration_fuction: ��õ�ǰƽ�����ļ���״̬
		// Returns:   bool ��ɼ���Ϊtrue����Ϊfalse
		// Other: �ú�������
		//************************************
		bool getCalCulateStatus() 
			{return IsCalculated;}
		//////////////////////////////////////////////////////////////////////////
		//����ӿڲ���
		//////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    Calculate
		// illustration_name: ƽ�����
		// illustration_fuction: ���ݲ�ͬ��ƽ��ԭ�����и��Ե�ƽ�����
		// Returns:   double �����ĵ�λȨ�����
		// Other: �ú������黯
		//************************************
		double virtual Calculate()=0;
};

