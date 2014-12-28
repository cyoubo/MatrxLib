#pragma once
#include "CommonHeader.h"

//������ǰ������˵��//////////////////////////////////////////////////////
class CVector;
//////////////////////////////////////////////////////////////////////////\
//ָ���ṩ�ľ������ķ�ʽ
enum SolveMethod
{
	Guass_Jardan,LU
};
/************************************************************************/
/* CMatrix ������
/************************************************************************/
class CMatrix
{
protected: 
	double* mElement;//�洢Ԫ�ص�ָ��
	int mRow,mCol;//�洢���кţ��к�

	//////////////////////////////////////////////////////////////////////////
	//�ڲ���������
	//////////////////////////////////////////////////////////////////////////
protected:
	//************************************
	// Method:    fab
	// illustration_name: �����ֵ����
	// illustration_fuction: ���ָ�������ľ���ֵ
	// Parameter: double temp �������ֵ�Ĳ���
	// Returns:   double ����ľ���ֵ
	// Other: 
	//************************************
	double fab(double temp){return temp>0.0?temp:-temp;}
	//************************************
	// Method:    swap
	// illustration_name: ��������
	// illustration_fuction: ʵ����������
	// Parameter: double & a ��������a�Լ����������b
	// Parameter: double & b ��������b�Լ����������a
	// Returns:   void 
	// Other: 
	//************************************
	void swap(double &a,double &b){double t=a;a=b;b=t;};
	//************************************
	// Method:    findpivot
	// illustration_name: ������Ԫ
	// illustration_fuction: ���Ҷ������Ԫ
	// Parameter: double & i �����Ԫ�кţ���0��ʼ��
	// Parameter: double & j �����Ԫ�кţ���0��ʼ��
	// Parameter: int index ��������ʽ����ţ�Ĭ�ϴ�0��ʼ��
	// Returns:   double ���ҵ�����Ԫ
	// Other: 
	//************************************
	double findpivot(int &i,int &j,int index=0);
	//************************************
	// Method:    sign
	// illustration_name: ����ź���
	// illustration_fuction: 
	// Parameter: double e
	// Parameter: double eps
	// Returns:   int
	// Other: 
	//************************************
	int sign(double e,double eps=0.000001);
public:	
	//////////////////////////////////////////////////////////////////////////
	//���캯������
	//////////////////////////////////////////////////////////////////////////
	//************************************
	// Method:    CMatrix
	// illustration_name: Ĭ�Ϲ��캯��
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
	// illustration_name:�������캯��
	// illustration_fuction: ʵ�־������Ŀ�������
	// Parameter: CMatrix & matrix ��������ԭʼ���ݾ���
	//************************************
	CMatrix(CMatrix& matrix);
	//************************************
	// Method:    ~CMatrix
	// illustration_name: ��������
	// illustration_fuction: ʵ�ֶ�̬�����ڴ���ͷ�
	// Parameter: void
	//************************************
	~CMatrix(void);


	//////////////////////////////////////////////////////////////////////////
	//���ܺ�������
	//////////////////////////////////////////////////////////////////////////
	//************************************
	// Method:    ScenseShow
	// illustration_name: ��Ļ�������
	// illustration_fuction: ʵ�־����������Ļ����ʾ���
	// Returns:   void
	//************************************
	void ScenseShow(char* title="---");
	//������
	//************************************
	// Method:    getRowAsCMatrix 
	// illustration_name: ���������
	// illustration_fuction: ��һά������ʽ��õ�ǰ�������ָ���б��һ������
	// Parameter: int index �б�
	// Returns:   CMatrix �����������ݵ�һά����
	// Other: 
	//************************************
	CMatrix getRowAsCMatrix(int index);
	//************************************
	// Method:    getRowAsCVector
	// illustration_name: ���������
	// illustration_fuction: ���������
	// Parameter: int index �б�
	// Returns:   CVector �����������ݵ�����
	// Other: 
	//************************************
	CVector getRowAsCVector(int index);
	//************************************
	// Method:    getColAsCMatrix
	// illustration_name: ���������
	// illustration_fuction: ��һά������ʽ��õ�ǰ�������ָ���б��һ������
	// Parameter: int index �б�
	// Returns:   CMatrix �����������ݵ�һά����
	// Other: 
	//************************************
	CMatrix getColAsCMatrix(int index);
	//************************************
	// Method:    getColAsCVector
	// illustration_name: ���������
	// illustration_fuction: ���������
	// Parameter: int index �б�
	// Returns:   CVector �����������ݵ�����
	// Other: 
	////************************************
	CVector getColAsCVector(int index);
	//************************************
	// Method:    setRow
	// illustration_name: ������Ԫ��
	// illustration_fuction: �޸Ļ����õ�ǰ��������һ�е�Ԫ��ֵ
	// Parameter: int index �б�
	// Parameter: double * values �����޸ĵ���ֵ����
	// Returns:   bool ���б�Խ��ʱ����false ���򷵻�true
	// Other: 
	//************************************
	bool setRow(int index,double* values);
	//************************************
	// Method:    setCol
	// illustration_name: ������Ԫ��
	// illustration_fuction: �޸Ļ����õ�ǰ��������һ�е�Ԫ��ֵ
	// Parameter: int index �б�
	// Parameter: double * values �����޸ĵ���ֵ����
	// Returns:   bool ���б�Խ��ʱ����false ���򷵻�true
	// Other: 
	//************************************
	bool setCol(int index,double* values);
	//************************************
	// Method:    setRow
	// illustration_name: ������Ԫ��
	// illustration_fuction: �޸Ļ����õ�ǰ��������һ�е�Ԫ��ֵ
	// Parameter: int index �б�
	// Parameter: CMatrix matrix �����޸ĵ���ֵһά����
	// Returns:   bool ���б�Խ��ʱ����false ���򷵻�true
	// Other: 
	//************************************
	bool setRow(int index,CMatrix matrix);
	//************************************
	// Method:    setCol
	// illustration_name: ������Ԫ��
	// illustration_fuction: �޸Ļ����õ�ǰ��������һ�е�Ԫ��ֵ
	// Parameter: int index �б�
	// Parameter: CMatrix matrix �����޸ĵ���ֵһά����
	// Returns:   bool ���б�Խ��ʱ����false ���򷵻�true
	// Other: 
	//************************************
	bool setCol(int index,CMatrix matrix);
	//************************************
	// Method:    AddRow
	// illustration_name: �����
	// illustration_fuction: �ڵ�ǰ��������ָ��λ�����һ������
	// Parameter: int index �б�
	// Parameter: double * values ���д��������ݵ�����
	// Parameter: int length ��������ĳ���
	// Returns:   bool �����鳤�Ȳ�ƥ��ʱ����false ���򷵻�true
	// Other: 
	//************************************
	bool AddRow(int index,double* values, int length);
	//************************************
	// Method:    AddCol
	// illustration_name: �����
	// illustration_fuction: �ڵ�ǰ��������ָ��λ�����һ������
	// Parameter: int index �б�
	// Parameter: double * values ���д��������ݵ�����
	// Parameter: int length ��������ĳ���
	// Returns:   bool �����鳤�Ȳ�ƥ��ʱ����false ���򷵻�true
	// Other: 
	//************************************
	bool AddCol(int index,double* values, int length);
	//************************************
	// Method:    AddRow
	// illustration_name: �����
	// illustration_fuction: �ڵ�ǰ��������ָ��λ�����һ������
	// Parameter: int index �б�
	// Parameter: CMatrix matrix ���д��������ݵ�һά����
	// Returns:   bool �����鳤�Ȳ�ƥ��ʱ����false ���򷵻�true
	// Other: 
	//************************************
	bool AddRow(int index,CMatrix matrix);
	//************************************
	// Method:    AddCol
	// illustration_name: �����
	// illustration_fuction: �ڵ�ǰ��������ָ��λ�����һ������
	// Parameter: int index �б�
	// Parameter: CMatrix matrix ���д��������ݵ�һά����
	// Returns:   bool �����鳤�Ȳ�ƥ��ʱ����false ���򷵻�true
	// Other: 
	//************************************
	bool AddCol(int index,CMatrix matrix);	
	//************************************
	// Method:    RemoveRow
	// illustration_name: �Ƴ���
	// illustration_fuction: �Ƴ���ָ��λ�õ�һ������
	// Parameter: int index ����
	// Returns:   CMatrix �����Ƴ������һά����
	// Other: 
	//************************************
	CMatrix RemoveRow(int index);
	//************************************
	// Method:    RemoveCol
	// illustration_name: �Ƴ���
	// illustration_fuction: �Ƴ���ָ��λ�õ�һ������
	// Parameter: int index �б�
	// Returns:   CMatrix �����Ƴ������һά����
	// Other: 
	//************************************
	CMatrix RemoveCol(int index);
	//************************************
	// Method:    getRowCount
	// illustration_name: �������
	// illustration_fuction: ��õ�ǰ������������
	// Returns:   int ����
	// Other: 
	//************************************
	int getRowCount();
	//************************************
	// Method:    getColCount
	// illustration_name: �������
	// illustration_fuction: ��õ�ǰ������������
	// Returns:   int ����
	// Other: 
	//************************************
	int getColCount();
	//************************************
	// Method:    Swaps
	// illustration_name: ����һ�л���һ��
	// illustration_fuction: ʵ��ָ�����л�����֮��Ľ���
	// Parameter: int from ���������л��еı�ţ���0��ʼ��
	// Parameter: int to ���������л��еı��(��0 ��ʼ)
	// Parameter: bool IsRow ����������Ϊtrue ����Ϊ������
	// Returns:   void
	// Other: 
	//************************************
	void Swaps(int from,int to,bool IsRow=false);
	//************************************
	// Method:    Trim
	// illustration_name: С������
	// illustration_fuction: ������Ԫ���о���ֵС��ָ������ֵ��Ϊ0
	// Parameter: double eps ָ�����ȣ�Ĭ��Ϊ0.000001
	// Returns:   CMatrix ���ص�ǰ������
	// Other: �÷����޸ĵ�ǰ������
	//************************************
	CMatrix Trim(double eps=0.000001);


	/**************************�������**********************************/
	//************************************
	// Method:    Transposition
	// illustration_name: ת��
	// illustration_fuction: ��ɵ�ǰ��������ת�ã��������µľ������
	// Returns:   CMatrix ���ת�ú���¾���
	// Other: 
	//************************************
	CMatrix Transposition();
	//************************************
	// Method:    Slove
	// illustration_name: ���Է������
	// illustration_fuction: ������Է��̣�
	// Parameter: CMatrix coe ��������ĳ�����
	// Parameter: SolveMethod Type ����ⷽ�̷���
	// Returns:   CMatrix ���̵Ľ�
	// Other:  �ð汾�ĺ���ֻ����Է����췽�������
	//************************************
	CMatrix Slove(CMatrix coe,SolveMethod Type);
	//************************************
	// Method:    Invert
	// illustration_name: ��������
	// illustration_fuction: ����Guass-jaddan������ȫѡ��Ԫ����
	// Parameter: CMatrix & outMat �洢������󣬸ú��������޸����ݱ���
	// Returns:   double
	// Other: ���ܻ��׳��Ƿ����쳣����������쳣
	//************************************
	double Invert(CMatrix& outMat);
	//************************************
	// Method:    Invert
	// illustration_name: ��������
	// illustration_fuction: ����Guass-jaddan������ȫѡ��Ԫ����
	// Parameter: void �÷������޸���������
	// Returns:   double 
	// Other: ���ܻ��׳��Ƿ����쳣����������쳣
	//************************************
	double Invert(void);
	//************************************
	// Method:    LU_Decomposition
	// illustration_name: �����LU�ֽ�
	// illustration_fuction: ʵ��nά�����LU�ֽ�
	// Parameter: CMatrix & LMatrix �ֽ���L����
	// Parameter: CMatrix & UMatrix �ֽ���U����
	// Returns:   bool �������Ϸֽ������򷵻�false ���򷵻�true
	// Other: ֻ�ܽ��з���ķֽ⡣
	//************************************
	bool LU_Decomposition(CMatrix& LMatrix,CMatrix& UMatrix);
	//************************************
	// Method:    QR_Decomposition
	// illustration_name: һ��ʵ�����QR�ֽ�
	// illustration_fuction: ���õ��㻯Householder�任����һ��m*n��ʵ�������QR�ֽ�
	// Parameter: CMatrix & Q �ֽ���Q���� m*m
	// Parameter: CMatrix & R �ֽ���R���� m*n
	// Returns:   bool �����ֽ�󷵻�true���򷵻�false
	// Other: ǰ������m>=n
	//************************************
	bool QR_Decomposition(CMatrix& Q,CMatrix& R);
	//************************************
	// Method:    Trace
	// illustration_name: ��
	// illustration_fuction: ��ȡ����ļ��������Խ���Ԫ�غ�
	// Returns:   double ��ǰ����ļ�
	// Other: ǰ����������ǰ����Ϊ����
	//************************************
	double Trace();
	//************************************
	// Method:    Det
	// illustration_name: ������ʽ
	// illustration_fuction: ��ȡ���������ʽֵ������Guass-jardan��Ϊ��������������Խ�Ԫ�ػ�ã� 
	// Returns:   double ��ǰ���������ʽ
	// Other: ǰ����������ǰ����Ϊ����
	//************************************
	double Det();
	//************************************
	// Method:    Rank
	// illustration_name: ������������
	// illustration_fuction: ���ø�˹ȫѡ��Ԫ����ȡ�����������
	// Returns:   int ������
	//************************************
	int Rank();
	//************************************
	// Method:    Hadamard
	// illustration_name: �������
	// illustration_fuction: ��ȡ�����Hadamard��������ӦԪ�صĳɼ�
	// Parameter: CMatrix & mat �����������
	// Returns:   CMatrix ��������Ľ������
	//************************************
	CMatrix Hadamard(CMatrix* mat);
	//************************************
	// Method:    Householder
	// illustration_name: ʩ��Householder�仯����ʵ����ΪHessberg��
	// illustration_fuction:ʩ��Householder�仯����ʵ����ΪHessberg��
	// Returns:   bool ����ɹ�����true
	//************************************
	CMatrix Householder();

	//************************************
	// Method:    Convolution
	// illustration_name: �������
	// illustration_fuction: ����nuclear�Ծ�����о������
	// Parameter: CMatrix nuclear ����ں�
	// Parameter: IgnoreBound=true �Ƿ���Ա߽�
	// Returns:   CMatrix �����ľ���
	// Other: ���������޸ĵ�ǰ������
	//************************************
	CMatrix Convolution(CMatrix &nuclear,bool IgnoreBound=true);






	//************************************
	// Method:    operator+
	// illustration_name: ����+�����
	// illustration_fuction: ʵ�����������������
	// Parameter: CMatrix matrix ���ӵľ���
	// Returns:   CMatrix �;���
	// Other: 
	//************************************
	CMatrix operator+(CMatrix matrix);
	//************************************
	// Method:    operator-
	// illustration_name: ����-�����
	// illustration_fuction:ʵ�����������������
	// Parameter: CMatrix matrix �����ľ���
	// Returns:   CMatrix �����
	// Other: 
	//************************************
	CMatrix operator-(CMatrix matrix);
	//************************************
	// Method:    operator=
	// illustration_name: ����=�����
	// illustration_fuction: ʵ����������ĸ�ֵ
	// Parameter: CMatrix matrix ���ڸ�ֵ�ľ���
	// Returns:   CMatrix& ��ǰ����ֵ�ľ����������
	// Other: 
	//************************************
	CMatrix& operator=(CMatrix matrix);
	//************************************
	// Method:    operator*
	// illustration_name: ����*�����
	// illustration_fuction: ʵ�������������
	// Parameter: double number ���˵ľ���
	// Returns:   CMatrix ������˵ľ���
	// Other: 
	//************************************
	CMatrix operator*(double number);
	//************************************
	// Method:    operator*
	// illustration_name: ����*�����
	// illustration_fuction: ʵ��������������
	// Parameter: CMatrix matrix ���˵ľ���
	// Returns:   CMatrix �������
	// Other: �����кŲ�ͳһ���򷵻�NULL
	//************************************
	CMatrix operator*(CMatrix matrix);
	//************************************
	// Method:    operator^
	// illustration_name: �����������
	// illustration_fuction: ��ɷ������ݷ�����
	// Parameter: int power ����
	// Returns:   CMatrix ����������Ľ������
	// Other: ������ȡֵ��ΧӦ>1
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
	//��̬��������
	//////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////
	//************************************
	// Method:    DiagMatrix
	// illustration_name: ��̬�����������Խ���
	// illustration_fuction: ����ָ��ά�������Խ���Ԫ�صĶԽ��߾�֤
	// Parameter: int n ά��
	// Parameter: double values ���Խ���Ԫ��
	// Returns:   CMatrix �����ľ���
	// Other: 
	//************************************
	static CMatrix DiagMatrix(int n,double values);
	//************************************
	// Method:    DiagMatrix
	// illustration_name: ��̬�����������Խ���
	// illustration_fuction: ����ָ��ά�������Խ���Ԫ�صĶԽ��߾�֤
	// Parameter: int n ά��
	// Parameter: double * values ���Խ���Ԫ������
	// Returns:   CMatrix �����ľ���
	// Other: 
	//************************************
	static CMatrix DiagMatrix(int n,double* values);
	//************************************
	// Method:    ZeroMatrix
	// illustration_name: ��̬����������0��
	// illustration_fuction: ����ָ��ά�ȵ�0����
	// Parameter: int n ά��
	// Returns:   CMatrix �����ľ���
	// Other: 
	//************************************
	static CMatrix ZeroMatrix(int n);
	//************************************
	// Method:    EyeMatrix
	// illustration_name: ��̬������������λ��
	// illustration_fuction: ����ָ��ά�ȵĵ�λ��
	// Parameter: int n ά��
	// Returns:   CMatrix �����ľ���
	// Other: 
	//************************************
	static CMatrix EyeMatrix(int n);

	static CMatrix ZeroMatrix(int m,int n);
	//************************************
	// Method:    CreateByVector
	// illustration_name: ͨ��������������
	// illustration_fuction: �������������ת��
	// Parameter: CVector & vec ���ڹ�����������
	// Returns:   CMatrix �����ľ���
	//************************************
	static CMatrix CreateByVector(CVector &vec);

	//////////////////////////////////////////////////////////////////////////
	//���ܺ����ľ�̬�ӿ�
	////////////////////////////////////////////////////////////////////////

	static CMatrix S_Invert(CMatrix &mat);

	static CMatrix S_Transposition(CMatrix &mat);

	static CMatrix S_Hadamard(CMatrix &mat1,CMatrix &mat2);

	static CMatrix S_Householder(CMatrix &mat1);

};


