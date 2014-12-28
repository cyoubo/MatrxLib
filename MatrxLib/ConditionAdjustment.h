#pragma once
#include "Matrix.h"
#include "AbstructAdjustment.h"
/************************************************************************/
/* ConditionAdjustment 条件平差类 
/************************************************************************/
class ConditionAdjustment : public AbstructAdjustment
{
	protected:
		CMatrix *A;//条件方程系数阵
		CMatrix *W;//条件方程常数向量（不符合值或条件方程闭合差） 
		CMatrix *k;//联系数
	public:
		//////////////////////////////////////////////////////////////////////////
		//构造方法部分
		//////////////////////////////////////////////////////////////////////////
		ConditionAdjustment(void){};
		ConditionAdjustment(CMatrix a,CMatrix w,CMatrix p);
		~ConditionAdjustment(void);
		//////////////////////////////////////////////////////////////////////////
		//功能函数部分
		//////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    getAMatrix
		// illustration_name: 获得输入的系数矩阵
		// illustration_fuction:
		// Returns:   CMatrix
		// Other: 
		//************************************
		CMatrix getAMatrix();
		CMatrix getWMatrix();
		void setObservationMatrix(CMatrix *obs);
		//////////////////////////////////////////////////////////////////////////
		//抽象接口部分(实现)
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

