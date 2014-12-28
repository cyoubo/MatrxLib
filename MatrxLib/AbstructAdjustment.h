 #pragma once

#include "CommonHeader.h"
/**
所有平差类的统一接口，虚基类
*/
class AbstructAdjustment
{
	protected:
		int N;//总观测数
		int T;//必要观测数
		//结果型变量
		CMatrix* V;//改正数向量
		CMatrix* Qvv;//改正数协因数阵
		double Rmse;//中误差
		CMatrix* Lg;//观测值改正数向量
		//输入型变量
		CMatrix* P;//权阵
		CMatrix* L;//观测值向量
		//标识符，用于标记是否进行过计算
		bool IsCalculated;
		//************************************
		// Method:    Calculate_Rmse
		// illustration_name: 计算单位权中误差
		// illustration_fuction: 按照sqrt(VtPV)的要求，计算当前平差对象的单位权中误差
		// Returns:   void 记录存于Rmse成员中
		// Other: 该方法为内部方法
		//************************************
		void Calculate_Rmse();
	public:
		//////////////////////////////////////////////////////////////////////////
		//构造方法部分
		//////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    AbstructAdjustment
		// illustration_name: 构造函数
		// illustration_fuction: 默认构造函数用于实现所有参数的0值初始化
		// Parameter: void 
		//************************************
		AbstructAdjustment(void);
		//************************************
		// Method:    AbstructAdjustment
		// illustration_name: 构造函数
		// illustration_fuction: 指定总观测数与必要观测数尽心构造
		// Parameter: int n 观测总数
		// Parameter: int t 必要观测数
		//************************************
		AbstructAdjustment(int n,int t);
		//************************************
		// Method:    AbstructAdjustment
		// illustration_name: 构造函数
		// illustration_fuction: 指定权阵、观测值向量与必要观测数进行构造
		// Parameter: CMatrix P 权阵
		// Parameter: CMatrix L 观测值向量
		// Parameter: int t 必要观测数
		//************************************
		AbstructAdjustment(CMatrix P,CMatrix L,int t);
		//************************************
		// Method:    ~AbstructAdjustment
		// illustration_name: 析构函数
		// illustration_fuction: 用于完成当前对象的析构
		// Parameter: void
		//************************************
		~AbstructAdjustment(void);
		//////////////////////////////////////////////////////////////////////////
		//功能函数部分
		//////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    getRmse
		// illustration_name: 获得单位权中误差
		// illustration_fuction: 在“完成计算”状态下，获取计算所得的单位权中误差
		// Returns:   double 获得的单位权中误差
		// Other: 前置条件getCalCulateStatus()的返回值为Ture
		//************************************
		double getRmse();
		//************************************
		// Method:    getCorrectionMatrix
		// illustration_name: 获得改正数向量
		// illustration_fuction: 在“完成计算”状态下，获得计算所得的改正数向量
		// Returns:   CMatrix （t*1）的矩阵表示的改正数向量
		// Other: 前置条件getCalCulateStatus()的返回值为Ture
		//************************************
		CMatrix getCorrectionMatrix();
		//************************************
		// Method:    getPowerMatrix
		// illustration_name: 获得输入权阵
		// illustration_fuction: 获得输入权阵
		// Returns:   CMatrix （n*n）的矩阵表示的权阵
		//************************************
		CMatrix getPowerMatrix();
		//************************************
		// Method:    getCorrectionCoFactorMatrix
		// illustration_name: 获得Qvv
		// illustration_fuction: 获得计算后的改正数协因数阵
		// Returns:   CMatrix 改正数协因数阵
		// Other: 
		//************************************
		CMatrix getCorrectionCoFactorMatrix();
		//************************************
		// Method:    getObservationMatrix
		// illustration_name: 获得观测值向量
		// illustration_fuction: 
		// Returns:   CMatrix 观测值向量
		// Other: 
		//************************************
		CMatrix getObservationMatrix();
		//************************************
		// Method:    getObservationCorrectionMatrix
		// illustration_name: 获取改正后观测值
		// illustration_fuction: 
		// Parameter: CMatrix * ObservationMatrix 当不指定初始的观测值时，默认使用当前对象自身的观测值
		// Returns:   CMatrix 改正后的观测值
		// Other: 
		//************************************
		CMatrix getObservationCorrectionMatrix(CMatrix *ObservationMatrix=NULL);
		//************************************
		// Method:    getCalCulateStatus
		// illustration_name: 获得“完成计算”状态
		// illustration_fuction: 获得当前平差对象的计算状态
		// Returns:   bool 完成计算为true否则为false
		// Other: 该函数内联
		//************************************
		bool getCalCulateStatus() 
			{return IsCalculated;}
		//////////////////////////////////////////////////////////////////////////
		//抽象接口部分
		//////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    Calculate
		// illustration_name: 平差计算
		// illustration_fuction: 根据不同的平差原理，进行各自的平差计算
		// Returns:   double 计算后的单位权中误差
		// Other: 该函数纯虚化
		//************************************
		double virtual Calculate()=0;
};

