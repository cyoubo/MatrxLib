#pragma once
#include "Matrix.h"
#include "AbstructAdjustment.h"
/************************************************************************/
/* ConditionAdjustment ����ƽ���� 
/************************************************************************/
class ConditionAdjustment : public AbstructAdjustment
{
	protected:
		CMatrix *A;//��������ϵ����
		CMatrix *W;//�������̳���������������ֵ���������̱պϲ 
		CMatrix *k;//��ϵ��
	public:
		//////////////////////////////////////////////////////////////////////////
		//���췽������
		//////////////////////////////////////////////////////////////////////////
		ConditionAdjustment(void){};
		ConditionAdjustment(CMatrix a,CMatrix w,CMatrix p);
		~ConditionAdjustment(void);
		//////////////////////////////////////////////////////////////////////////
		//���ܺ�������
		//////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    getAMatrix
		// illustration_name: ��������ϵ������
		// illustration_fuction:
		// Returns:   CMatrix
		// Other: 
		//************************************
		CMatrix getAMatrix();
		CMatrix getWMatrix();
		void setObservationMatrix(CMatrix *obs);
		//////////////////////////////////////////////////////////////////////////
		//����ӿڲ���(ʵ��)
		//////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    Calculate
		// illustration_name:
		// illustration_fuction:
		// Returns:   double
		// Other: 
		//************************************
		double Calculate();
};

