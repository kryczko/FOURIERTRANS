#include <iostream>
#include <fstream>
#include <string>
#include <fftw3.h>
#include <cmath>

using namespace std;
	
int main()
{
	ofstream output;
	output.open("function.dat");
	int N = 500;
	double *function;
	function = new double [N];
	for ( int i = 0; i < 500; i ++)
	{
		function[i] = exp(cos(i/10.)) + 4*sin(i/10.);
	}
	
	fftw_complex *out;
	out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * (N/2)+1);
	fftw_plan p;
	p = fftw_plan_dft_r2c_1d(N,function,out,FFTW_ESTIMATE);
	fftw_execute(p);
	
	for (int i = 0; i < (N/2)+1; i ++)
	{
		output << i << "  " << out[i][0] << endl;
	}
output.close();
return 0;
}
