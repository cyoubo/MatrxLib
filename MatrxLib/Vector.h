#pragma once

#include "CommonHeader.h"
//相关类的前置引用说明//////////////////////////////////////////////////////
class CMatrix;
//////////////////////////////////////////////////////////////////////////\


/************************************************************************/
/* CVector 向量类
/************************************************************************/
class CVector
{
	protected:
		double *mElement;//元素指针
		int length;//向量长度 
		bool IsColumn;//是否未列向量
	public:
		//////////////////////////////////////////////////////////////////////////
		//构造方法部分
		//////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    CVector
		// illustration_name: 构造函数
		// illustration_fuction: 默认构造函数，构造单位列向量
		// Parameter: int count 指定向量的长度， 
		//************************************
		CVector(int count=3);
		//************************************
		// Method:    CVector
		// illustration_name: 构造函数
		// illustration_fuction: 指定数据，长度以及向量方向构造
		// Parameter: double * p 存有数据的double数组
		// Parameter: int count 向量的长度
		// Parameter: bool isCol 指定向量方向，true为列向量
		//************************************
		CVector(double *p,int count,bool isCol=true);
		//************************************
		// Method:    CVector
		// illustration_name: 拷贝构造函数
		// Parameter: CVector & c 待拷贝的向量对象
		//************************************
		CVector(CVector &c);
		//************************************
		// Method:    ~CVector
		// illustration_name: 析构函数
		// illustration_fuction: 完成内存空间的释放
		//************************************
		~CVector(void);
		///////////////////////////////////////////////////////////////////////////////
		//功能函数
		///////////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    CrossProduct
		// illustration_name: 向量的叉积
		// illustration_fuction: 完成两个3维向量的外积运算
		// Parameter: CVector & vec 乘向量
		// Returns:   CVector 外积结果向量
		// Other: 该版本中智能处理三维向量的叉乘
		//************************************
		CVector CrossProduct(CVector &vec);
		//************************************
		// Method:    MatrixProduct
		// illustration_name: 向量矩阵乘
		// illustration_fuction: 完成列向量*行向量并恢复矩阵的乘法
		// Parameter: CVector & vec 待乘的行向量
		// Returns:   CMatrix 结果矩阵
		// Other: 要求两者向量维度一致，方向相反，若相同，则进行点乘运算
		//************************************
		CMatrix MatrixProduct(CVector &vec);
		//************************************
		// Method:    Mod
		// illustration_name: 向量求模
		// Returns:   double 当前向量的模长
		//************************************
		double Mod();
		//************************************
		// Method:    Normalize
		// illustration_name: 向量的规范化
		// illustration_fuction: 对当前向量进行规范化处理
		// Returns:   void
		// Other:  该方法修改当前对象本身
		//************************************
		void Normalize();
		//************************************
		// Method:    Transportation
		// illustration_name: 向量转置(内联)
		// illustration_fuction: 改变向量的行列方向
		// Returns:   void 
		// Other: 该方法修改当前对象本身
		//************************************
		void Transportation()
			{this->IsColumn=!this->IsColumn;}
		//************************************
		// Method:    getDirection
		// illustration_name: 获得当前对象行列方向（内联）
		// Returns:   bool true为列向量否则为行向量
		//************************************
		bool getDirection()
			{return this->IsColumn;}
		//************************************
		// Method:    getLength
		// illustration_name: 获取当前向量的长度
		// Returns:   int 向量的长度
		//************************************
		int getLength()
			{return this->length;}
		///////////////////////////////////////////////////////////////////////////////
		//静态方法
		///////////////////////////////////////////////////////////////////////////////
		//************************************
		// Method:    GetDistance
		// illustration_name: 计算向量间距离
		// Parameter: CVector & vec1 起点向量
		// Parameter: CVector & vec2 终点向量
		// Returns:   double 欧氏距离
		//************************************
		double static GetDistance(CVector &vec1,CVector &vec2); 
		//************************************
		// Method:    NormalizetoCVector
		// illustration_name: 向量规范化
		// illustration_fuction:
		// Returns:   CVector 规范化后的向量
		//************************************
		CVector static NormalizetoCVector();
		//************************************
		// Method:    CreateZeroVector
		// illustration_name: 构建0向量
		// illustration_fuction: 构建指定长度，所有元素均为0的列向量
		// Parameter: int n 自定长度
		// Returns:   CVector 构建的0向量
		//************************************
		CVector CreateZeroVector(int n);
		///////////////////////////////////////////////////////////////////////////////
		//重载运算符
		///////////////////////////////////////////////////////////////////////////////
		CVector& operator=(CVector &c);
		//************************************
		// Method:    operator+
		// illustration_name: 向量相加
		// illustration_fuction:
		// Parameter: CVector & c 待加向量
		// Returns:   CVector 结果向量
		// Other: 前置条件，向量的维度应一致，否则会引发异常
		//************************************
		CVector operator+(CVector &c);
		//************************************
		// Method:    operator-
		// illustration_name: 向量取反
		// illustration_fuction: 将向量的元素均取反
		// Returns:   CVector 取反后的向量
		// Other: 改函数不修改该当前对象本身
		//************************************
		CVector operator-();
		//************************************
		// Method:    operator-
		// illustration_name: 向量相减
		// illustration_fuction:
		// Parameter: CVector & c 待减向量
		// Returns:   CVector 结果向量
		// Other: 前置条件，向量的维度应一致，否则会引发异常
		//************************************
		CVector operator-(CVector &c);
		//************************************
		// Method:    operator*
		// illustration_name: 向量与数的乘法
		// Parameter: double num 被乘数
		// Returns:   CVector 结果向量
		// Other:  改方法不修改当前对象本身
		//************************************
		CVector operator*(double num);
		//************************************
		// Method:    operator*
		// illustration_name: 向量的点乘
		// illustration_fuction: 计算向量的内积
		// Parameter: CVector & vec 待乘向量
		// Returns:   double 内积
		// Other: 前置条件向量的维度应该一致
		//************************************
		double operator*(CVector &vec);
		
		bool operator==(CVector &vec);
		//************************************
		// Method:    operator[]
		// illustration_name:重载[]
		// illustration_fuction:获得向量中指定下标的元素
		// Parameter: int i 从0开始的元素下标
		// Returns:   double& 返回的元素引用
		//************************************
		double& operator[] (int i);


};

