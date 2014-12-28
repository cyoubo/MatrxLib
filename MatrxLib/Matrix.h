#pragma once
#include "CommonHeader.h"

//相关类的前置引用说明//////////////////////////////////////////////////////
class CVector;
//////////////////////////////////////////////////////////////////////////\
//指定提供的矩阵求解的方式
enum SolveMethod
{
	Guass_Jardan,LU
};
/************************************************************************/
/* CMatrix 矩阵类
/************************************************************************/
class CMatrix
{
protected: 
	double* mElement;//存储元素的指针
	int mRow,mCol;//存储的行号，列号

	//////////////////////////////////////////////////////////////////////////
	//内部方法部分
	//////////////////////////////////////////////////////////////////////////
protected:
	//************************************
	// Method:    fab
	// illustration_name: 求绝对值函数
	// illustration_fuction: 求得指定参数的绝对值
	// Parameter: double temp 待求绝对值的参数
	// Returns:   double 所求的绝对值
	// Other: 
	//************************************
	double fab(double temp){return temp>0.0?temp:-temp;}
	//************************************
	// Method:    swap
	// illustration_name: 两数交换
	// illustration_fuction: 实现两数交换
	// Parameter: double & a 待交换的a以及被交换后的b
	// Parameter: double & b 待交换的b以及被交换后的a
	// Returns:   void 
	// Other: 
	//************************************
	void swap(double &a,double &b){double t=a;a=b;b=t;};
	//************************************
	// Method:    findpivot
	// illustration_name: 查找主元
	// illustration_fuction: 查找对象的主元
	// Parameter: double & i 输出主元行号（从0开始）
	// Parameter: double & j 输出主元列号（从0开始）
	// Parameter: int index 输入余子式的序号（默认从0开始）
	// Returns:   double 查找到的主元
	// Other: 
	//************************************
	double findpivot(int &i,int &j,int index=0);
	//************************************
	// Method:    sign
	// illustration_name: 求符号函数
	// illustration_fuction: 
	// Parameter: double e
	// Parameter: double eps
	// Returns:   int
	// Other: 
	//************************************
	int sign(double e,double eps=0.000001);
public:	
	//////////////////////////////////////////////////////////////////////////
	//构造函数部分
	//////////////////////////////////////////////////////////////////////////
	//************************************
	// Method:    CMatrix
	// illustration_name: 默认构造函数
	// illustration_fuction:
	// Parameter: void
	// Returns:   
	// Other: 
	//************************************
	CMatrix(void);
	//************************************
	// Method:    CMatrix
	// illustration_name:
	// illustration_fuction:
	// Parameter: int row
	// Parameter: int col
	// Returns:   
	// Other: 
	//************************************
	CMatrix(int row,int col);
	//************************************
	// Method:    CMatrix
	// illustration_name:
	// illustration_fuction:
	// Parameter: const double * values
	// Parameter: int length
	// Parameter: int row
	// Parameter: int col
	// Returns:   
	// Other: 
	//************************************
	CMatrix(const double* values,int row=0,int col=0);
	//************************************
	// Method:    CMatrix
	// illustration_name:拷贝构造函数
	// illustration_fuction: 实现矩阵对象的拷贝构造
	// Parameter: CMatrix & matrix 待拷贝的原始数据矩阵
	//************************************
	CMatrix(CMatrix& matrix);
	//************************************
	// Method:    ~CMatrix
	// illustration_name: 析构函数
	// illustration_fuction: 实现动态分配内存的释放
	// Parameter: void
	//************************************
	~CMatrix(void);


	//////////////////////////////////////////////////////////////////////////
	//功能函数部分
	//////////////////////////////////////////////////////////////////////////
	//************************************
	// Method:    ScenseShow
	// illustration_name: 屏幕输出函数
	// illustration_fuction: 实现矩阵对象在屏幕的显示输出
	// Returns:   void
	//************************************
	void ScenseShow(char* title="---");
	//访问器
	//************************************
	// Method:    getRowAsCMatrix 
	// illustration_name: 获得行向量
	// illustration_fuction: 以一维矩阵形式获得当前矩阵对象指定行标的一行数据
	// Parameter: int index 行标
	// Returns:   CMatrix 存有所得数据的一维矩阵
	// Other: 
	//************************************
	CMatrix getRowAsCMatrix(int index);
	//************************************
	// Method:    getRowAsCVector
	// illustration_name: 获得行向量
	// illustration_fuction: 获得行向量
	// Parameter: int index 行标
	// Returns:   CVector 存有所得数据的向量
	// Other: 
	//************************************
	CVector getRowAsCVector(int index);
	//************************************
	// Method:    getColAsCMatrix
	// illustration_name: 获得列向量
	// illustration_fuction: 以一维矩阵形式获得当前矩阵对象指定列标的一行数据
	// Parameter: int index 列标
	// Returns:   CMatrix 存有所得数据的一维矩阵
	// Other: 
	//************************************
	CMatrix getColAsCMatrix(int index);
	//************************************
	// Method:    getColAsCVector
	// illustration_name: 获得列向量
	// illustration_fuction: 获得列向量
	// Parameter: int index 列标
	// Returns:   CVector 存有所得数据的向量
	// Other: 
	////************************************
	CVector getColAsCVector(int index);
	//************************************
	// Method:    setRow
	// illustration_name: 设置行元素
	// illustration_fuction: 修改或设置当前矩阵对象的一行的元素值
	// Parameter: int index 行标
	// Parameter: double * values 用于修改的数值数组
	// Returns:   bool 当行标越界时返回false 否则返回true
	// Other: 
	//************************************
	bool setRow(int index,double* values);
	//************************************
	// Method:    setCol
	// illustration_name: 设置列元素
	// illustration_fuction: 修改或设置当前矩阵对象的一列的元素值
	// Parameter: int index 列标
	// Parameter: double * values 用于修改的数值数组
	// Returns:   bool 当列标越界时返回false 否则返回true
	// Other: 
	//************************************
	bool setCol(int index,double* values);
	//************************************
	// Method:    setRow
	// illustration_name: 设置行元素
	// illustration_fuction: 修改或设置当前矩阵对象的一行的元素值
	// Parameter: int index 行标
	// Parameter: CMatrix matrix 用于修改的数值一维矩阵
	// Returns:   bool 当行标越界时返回false 否则返回true
	// Other: 
	//************************************
	bool setRow(int index,CMatrix matrix);
	//************************************
	// Method:    setCol
	// illustration_name: 设置列元素
	// illustration_fuction: 修改或设置当前矩阵对象的一列的元素值
	// Parameter: int index 列标
	// Parameter: CMatrix matrix 用于修改的数值一维矩阵
	// Returns:   bool 当列标越界时返回false 否则返回true
	// Other: 
	//************************************
	bool setCol(int index,CMatrix matrix);
	//************************************
	// Method:    AddRow
	// illustration_name: 添加行
	// illustration_fuction: 在当前矩阵对象的指定位置添加一行数据
	// Parameter: int index 行标
	// Parameter: double * values 存有带插入数据的数组
	// Parameter: int length 插入数组的长度
	// Returns:   bool 当数组长度不匹配时返回false 否则返回true
	// Other: 
	//************************************
	bool AddRow(int index,double* values, int length);
	//************************************
	// Method:    AddCol
	// illustration_name: 添加列
	// illustration_fuction: 在当前矩阵对象的指定位置添加一列数据
	// Parameter: int index 列标
	// Parameter: double * values 存有带插入数据的数组
	// Parameter: int length 插入数组的长度
	// Returns:   bool 当数组长度不匹配时返回false 否则返回true
	// Other: 
	//************************************
	bool AddCol(int index,double* values, int length);
	//************************************
	// Method:    AddRow
	// illustration_name: 添加行
	// illustration_fuction: 在当前矩阵对象的指定位置添加一行数据
	// Parameter: int index 行标
	// Parameter: CMatrix matrix 存有带插入数据的一维矩阵
	// Returns:   bool 当数组长度不匹配时返回false 否则返回true
	// Other: 
	//************************************
	bool AddRow(int index,CMatrix matrix);
	//************************************
	// Method:    AddCol
	// illustration_name: 添加列
	// illustration_fuction: 在当前矩阵对象的指定位置添加一列数据
	// Parameter: int index 列标
	// Parameter: CMatrix matrix 存有带插入数据的一维矩阵
	// Returns:   bool 当数组长度不匹配时返回false 否则返回true
	// Other: 
	//************************************
	bool AddCol(int index,CMatrix matrix);	
	//************************************
	// Method:    RemoveRow
	// illustration_name: 移除行
	// illustration_fuction: 移除在指定位置的一行数据
	// Parameter: int index 航标
	// Returns:   CMatrix 存有移除结果的一维矩阵
	// Other: 
	//************************************
	CMatrix RemoveRow(int index);
	//************************************
	// Method:    RemoveCol
	// illustration_name: 移除列
	// illustration_fuction: 移除在指定位置的一列数据
	// Parameter: int index 列标
	// Returns:   CMatrix 存有移除结果的一维矩阵
	// Other: 
	//************************************
	CMatrix RemoveCol(int index);
	//************************************
	// Method:    getRowCount
	// illustration_name: 获得行数
	// illustration_fuction: 获得当前矩阵对象的行数
	// Returns:   int 行数
	// Other: 
	//************************************
	int getRowCount();
	//************************************
	// Method:    getColCount
	// illustration_name: 获得列数
	// illustration_fuction: 获得当前矩阵对象的列数
	// Returns:   int 列数
	// Other: 
	//************************************
	int getColCount();
	//************************************
	// Method:    Swaps
	// illustration_name: 交换一行或者一列
	// illustration_fuction: 实现指定两行或两列之间的交换
	// Parameter: int from 待交换的行或列的编号（从0开始）
	// Parameter: int to 被交换的行货列的编号(从0 开始)
	// Parameter: bool IsRow 若交换行则为true 否则为交换列
	// Returns:   void
	// Other: 
	//************************************
	void Swaps(int from,int to,bool IsRow=false);
	//************************************
	// Method:    Trim
	// illustration_name: 小数整理
	// illustration_fuction: 将矩阵元素中绝对值小于指定精度值置为0
	// Parameter: double eps 指定精度，默认为0.000001
	// Returns:   CMatrix 返回当前对象本身
	// Other: 该方法修改当前对象本身
	//************************************
	CMatrix Trim(double eps=0.000001);


	/**************************矩阵操作**********************************/
	//************************************
	// Method:    Transposition
	// illustration_name: 转置
	// illustration_fuction: 完成当前矩阵对象的转置，并赋予新的矩阵对象
	// Returns:   CMatrix 完成转置后的新矩阵
	// Other: 
	//************************************
	CMatrix Transposition();
	//************************************
	// Method:    Slove
	// illustration_name: 线性方程求解
	// illustration_fuction: 求解线性方程，
	// Parameter: CMatrix coe ：方程组的常数项
	// Parameter: SolveMethod Type ：求解方程方法
	// Returns:   CMatrix 方程的解
	// Other:  该版本的函数只能针对非奇异方程组求解
	//************************************
	CMatrix Slove(CMatrix coe,SolveMethod Type);
	//************************************
	// Method:    Invert
	// illustration_name: 矩阵求逆
	// illustration_fuction: 利用Guass-jaddan法进行全选主元求逆
	// Parameter: CMatrix & outMat 存储输出矩阵，该函数不会修改数据本身
	// Returns:   double
	// Other: 可能会抛出非方阵异常与奇异矩阵异常
	//************************************
	double Invert(CMatrix& outMat);
	//************************************
	// Method:    Invert
	// illustration_name: 矩阵求逆
	// illustration_fuction: 利用Guass-jaddan法进行全选主元求逆
	// Parameter: void 该方法将修改自身数据
	// Returns:   double 
	// Other: 可能会抛出非方阵异常与奇异矩阵异常
	//************************************
	double Invert(void);
	//************************************
	// Method:    LU_Decomposition
	// illustration_name: 方阵的LU分解
	// illustration_fuction: 实现n维方阵的LU分解
	// Parameter: CMatrix & LMatrix 分解后的L矩阵
	// Parameter: CMatrix & UMatrix 分解后的U矩阵
	// Returns:   bool 若不符合分解条件则返回false 否则返回true
	// Other: 只能进行方阵的分解。
	//************************************
	bool LU_Decomposition(CMatrix& LMatrix,CMatrix& UMatrix);
	//************************************
	// Method:    QR_Decomposition
	// illustration_name: 一般实矩阵的QR分解
	// illustration_fuction: 利用电算化Householder变换，对一般m*n的实矩阵进行QR分解
	// Parameter: CMatrix & Q 分解后的Q矩阵 m*m
	// Parameter: CMatrix & R 分解后的R矩阵 m*n
	// Returns:   bool 正常分解后返回true否则返回false
	// Other: 前置条件m>=n
	//************************************
	bool QR_Decomposition(CMatrix& Q,CMatrix& R);
	//************************************
	// Method:    Trace
	// illustration_name: 求迹
	// illustration_fuction: 求取矩阵的迹，即主对角线元素和
	// Returns:   double 当前矩阵的迹
	// Other: 前置条件：当前对象为方阵
	//************************************
	double Trace();
	//************************************
	// Method:    Det
	// illustration_name: 求行列式
	// illustration_fuction: 求取矩阵的行列式值（采用Guass-jardan化为三角阵后联乘主对角元素获得） 
	// Returns:   double 当前矩阵的行列式
	// Other: 前置条件：当前对象为方阵
	//************************************
	double Det();
	//************************************
	// Method:    Rank
	// illustration_name: 矩阵求行秩数
	// illustration_fuction: 采用高斯全选主元法求取矩阵的行秩数
	// Returns:   int 行秩数
	//************************************
	int Rank();
	//************************************
	// Method:    Hadamard
	// illustration_name: 阿达玛积
	// illustration_fuction: 求取矩阵的Hadamard积，即对应元素的成绩
	// Parameter: CMatrix & mat 进行运算矩阵
	// Returns:   CMatrix 阿达玛积的结果矩阵
	//************************************
	CMatrix Hadamard(CMatrix* mat);
	//************************************
	// Method:    Householder
	// illustration_name: 施行Householder变化，将实矩阵化为Hessberg阵
	// illustration_fuction:施行Householder变化，将实矩阵化为Hessberg阵
	// Returns:   bool 计算成功返回true
	//************************************
	CMatrix Householder();

	//************************************
	// Method:    Convolution
	// illustration_name: 卷积函数
	// illustration_fuction: 利用nuclear对矩阵进行卷积运算
	// Parameter: CMatrix nuclear 卷积内核
	// Parameter: IgnoreBound=true 是否忽略边界
	// Returns:   CMatrix 处理后的矩阵
	// Other: 本方法不修改当前对象本身
	//************************************
	CMatrix Convolution(CMatrix &nuclear,bool IgnoreBound=true);






	//************************************
	// Method:    operator+
	// illustration_name: 重载+运算符
	// illustration_fuction: 实现两个矩阵对象的相加
	// Parameter: CMatrix matrix 待加的矩阵
	// Returns:   CMatrix 和矩阵
	// Other: 
	//************************************
	CMatrix operator+(CMatrix matrix);
	//************************************
	// Method:    operator-
	// illustration_name: 重载-运算符
	// illustration_fuction:实现两个矩阵对象的相减
	// Parameter: CMatrix matrix 待减的矩阵
	// Returns:   CMatrix 差矩阵
	// Other: 
	//************************************
	CMatrix operator-(CMatrix matrix);
	//************************************
	// Method:    operator=
	// illustration_name: 重载=运算符
	// illustration_fuction: 实现两个矩阵的赋值
	// Parameter: CMatrix matrix 用于赋值的矩阵
	// Returns:   CMatrix& 当前被赋值的矩阵对象引用
	// Other: 
	//************************************
	CMatrix& operator=(CMatrix matrix);
	//************************************
	// Method:    operator*
	// illustration_name: 重载*运算符
	// illustration_fuction: 实现数与矩阵的相乘
	// Parameter: double number 待乘的矩阵
	// Returns:   CMatrix 完成数乘的矩阵
	// Other: 
	//************************************
	CMatrix operator*(double number);
	//************************************
	// Method:    operator*
	// illustration_name: 重载*运算符
	// illustration_fuction: 实现两个矩阵的相乘
	// Parameter: CMatrix matrix 待乘的矩阵
	// Returns:   CMatrix 结果矩阵
	// Other: 若行列号不统一，则返回NULL
	//************************************
	CMatrix operator*(CMatrix matrix);
	//************************************
	// Method:    operator^
	// illustration_name: 方阵的幂运算
	// illustration_fuction: 完成方正的幂方运算
	// Parameter: int power 幂数
	// Returns:   CMatrix 完成幂运算后的结果矩阵
	// Other: 幂数的取值范围应>1
	//************************************
	CMatrix operator^(int power);
	//************************************
	// Method:    operator()
	// illustration_name:
	// illustration_fuction:
	// Parameter: int i
	// Parameter: int j
	// Returns:   double&
	// Other: 
	//************************************
	double& CMatrix::operator()(int i,int j);





	//////////////////////////////////////////////////////////////////////////
	//静态方法部分
	//////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////
	//************************************
	// Method:    DiagMatrix
	// illustration_name: 静态方法，构建对角阵
	// illustration_fuction: 构建指定维度与主对角线元素的对角线举证
	// Parameter: int n 维度
	// Parameter: double values 主对角线元素
	// Returns:   CMatrix 构建的矩阵
	// Other: 
	//************************************
	static CMatrix DiagMatrix(int n,double values);
	//************************************
	// Method:    DiagMatrix
	// illustration_name: 静态方法，构建对角阵
	// illustration_fuction: 构建指定维度与主对角线元素的对角线举证
	// Parameter: int n 维度
	// Parameter: double * values 主对角线元素数组
	// Returns:   CMatrix 构建的矩阵
	// Other: 
	//************************************
	static CMatrix DiagMatrix(int n,double* values);
	//************************************
	// Method:    ZeroMatrix
	// illustration_name: 静态方法，构建0阵
	// illustration_fuction: 构建指定维度的0矩阵
	// Parameter: int n 维度
	// Returns:   CMatrix 构建的矩阵
	// Other: 
	//************************************
	static CMatrix ZeroMatrix(int n);
	//************************************
	// Method:    EyeMatrix
	// illustration_name: 静态方法，构建单位阵
	// illustration_fuction: 构建指定维度的单位阵
	// Parameter: int n 维度
	// Returns:   CMatrix 构建的矩阵
	// Other: 
	//************************************
	static CMatrix EyeMatrix(int n);

	static CMatrix ZeroMatrix(int m,int n);
	//************************************
	// Method:    CreateByVector
	// illustration_name: 通过向量构建矩阵
	// illustration_fuction: 完成向量与矩阵的转换
	// Parameter: CVector & vec 用于构造矩阵的向量
	// Returns:   CMatrix 构造后的矩阵
	//************************************
	static CMatrix CreateByVector(CVector &vec);

	//////////////////////////////////////////////////////////////////////////
	//功能函数的静态接口
	////////////////////////////////////////////////////////////////////////

	static CMatrix S_Invert(CMatrix &mat);

	static CMatrix S_Transposition(CMatrix &mat);

	static CMatrix S_Hadamard(CMatrix &mat1,CMatrix &mat2);

	static CMatrix S_Householder(CMatrix &mat1);

};


