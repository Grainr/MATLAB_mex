#include "median.h"
#define DATA  prhs[0]
#define POINT prhs[1]
#define MIDDATA plhs[0]

// 函数实现了中值滤波器
// 中值实现采用partition算法（对数据进行部分快速排序）
// 有两个输入参数，一个输出参数
// 输入参数0为需要中值滤波的数据
// 输入参数1为中值滤波点数p（在滤波点左右各取p个点，滤波后该点为2p+1个点的中值）
// 输出滤波后信号
// 注意matlab输入数据不应有nan和inf
// 若输入向量，则按向量滤波
// 若输入矩阵，则按列滤波


void mexFunction(int nlhs, mxArray *plhs[], 
	int nrhs, const mxArray *prhs[])
{
	if (nrhs != 2)
			mexErrMsgTxt("Wrong number of input arguments.\n");
		// 检查输入变量数量是否正确，否则报错

		if (nlhs > 1)
			mexErrMsgTxt("Too many output argumnents.\n");
		// 检查输出变量数量是否正确，否则报错



		size_t M = (mxGetM(DATA));
		size_t N = (mxGetN(DATA));
		// 得到输入矩阵A的行数和列数

		MIDDATA = mxCreateDoubleMatrix(M, N, mxREAL);
		// 为输出矩阵B分配存储空间

		double *data = mxGetPr(DATA);
		double *middata = mxGetPr(MIDDATA);
		size_t point = (size_t)*(mxGetPr(POINT));
		midfilt_t(data, middata, M*N, point);
}