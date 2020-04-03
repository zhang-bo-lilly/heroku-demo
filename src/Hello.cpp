
#include "Hello.hpp"

void runHello(int x) {
    std::cout << "Hello " << x << std::endl;
}

void runCalc(double* pIn, int nIn, double* pOut, int nOut) {
    double min = *pIn;
    double max = *pIn;
    double sum = 0;
    for(int i=0; i<nIn; ++i) {
	sum += *(pIn+i);
    }
    double ave = sum/nIn;
    for(int i=1; i<nIn; ++i) {
	if(*(pIn+i) < min) {
	    min = *(pIn+i);
	}
	else if(*(pIn+i) > max) {
	    max = *(pIn+i);
	}
    }
    *pOut = min;
    *(pOut+1) = max;
    *(pOut+2) = ave;
}
