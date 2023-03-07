//============================================================================
// Name         : IntegralMethod.h
// Author       : Abdurrahman Nurhakim
// Version      : 2.1.0
// GUI			: Eclipse IDE (This library can also be used in Arduino IDE, STM32Cube, etc)
// Description  : Several Itegral Method in C++
//============================================================================

struct FX {
	float X_1;
	float X_2;
	float X_3;
	float X_4;
	float FX_1;
};

class IntegralMethod {
public:
	IntegralMethod();
	float Basic(float X, float DT); ///Basic Integral
	float Trapezoid(float X, float DT); ///Trapezoid Rule
	float Simpsons_1_3(float X, float DT); ///Simpsons 1/3 Rule
	float Simpsons_3_8(float X, float DT); ///Simpsons 3/8 Rule
	float Boole(float X, float DT); ///Boole's Rule
	float _2rd_Adam_BashForth_Moulton(float X, float DT); ///2rd Order Adam BashForth MoultonRule
	float _3rd_Adam_BashForth_Moulton(float X, float DT); ///3rd Order Adam BashForth MoultonRule
	void ResetStruct(); ///Reset Accumulation Value
};
