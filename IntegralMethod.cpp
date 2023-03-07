//============================================================================
// Name         : IntegralMethod.cpp
// Author       : Abdurrahman Nurhakim
// Version      : 2.1.0
// GUI		: Eclipse IDE (This library can also be used in Arduino IDE, STM32Cube, etc)
// Description  : Several Integral Method in C++
//============================================================================
#include "IntegralMethod.h"

struct FX _Basic;
struct FX _Trapezoid;
struct FX _Simpsons_1_3;
struct FX _Simpsons_3_8;
struct FX _Boole;
struct FX _2rd_ABM;
struct FX _3rd_ABM;
struct FX reset { };

/**
 * Variable:
 * DT = sampling time
 * X = Input Value
**/

IntegralMethod::IntegralMethod() {

}

float IntegralMethod::Basic(float X, float DT) {
	float FX;
	FX = X * DT + _Basic.FX_1;
	_Basic.FX_1 = FX;
	return FX;
}

// Reference : https://ieeexplore.ieee.org/document/8708754
float IntegralMethod::Trapezoid(float X, float DT) {
	float FX;
	FX += (((X + _Trapezoid.X_1) / 2) * DT) + _Trapezoid.FX_1;
	_Trapezoid.FX_1 = FX;
	_Trapezoid.X_2 = _Trapezoid.X_1;
	_Trapezoid.X_1 = X;

	return FX;
}

// Reference : https://ieeexplore.ieee.org/document/8708754
float IntegralMethod::Simpsons_1_3(float X, float DT) {
	float FX;
	FX = (((X + (4 * _Simpsons_1_3.X_1) + _Simpsons_1_3.X_2) / 6) * DT)
			+ _Simpsons_1_3.FX_1;
	_Simpsons_1_3.FX_1 = FX;
	_Simpsons_1_3.X_2 = _Simpsons_1_3.X_1;
	_Simpsons_1_3.X_1 = X;
	return FX;
}

// Reference : https://ieeexplore.ieee.org/document/8708754
float IntegralMethod::Simpsons_3_8(float X, float DT) {
	float FX;
	FX = (((X + (3 * _Simpsons_3_8.X_1) + (3 * _Simpsons_3_8.X_2)
			+ _Simpsons_3_8.X_3) / 8) * DT) + _Simpsons_3_8.FX_1;
	_Simpsons_3_8.FX_1 = FX;
	_Simpsons_3_8.X_3 = _Simpsons_3_8.X_2;
	_Simpsons_3_8.X_2 = _Simpsons_3_8.X_1;
	_Simpsons_3_8.X_1 = X;
	return FX;
}

// Reference : https://ieeexplore.ieee.org/document/8708754
float IntegralMethod::Boole(float X, float DT) {
	float FX;
	FX = ((((7 * X) + (32 * _Boole.X_1) + (12 * _Boole.X_2) + (32 * _Boole.X_3)
			+ (7 * _Boole.X_4)) / 90) * DT) + _Boole.FX_1;
	_Boole.FX_1 = FX;
	_Boole.X_4 = _Boole.X_3;
	_Boole.X_3 = _Boole.X_2;
	_Boole.X_2 = _Boole.X_1;
	_Boole.X_1 = X;
	return FX;
}

// Reference : https://ieeexplore.ieee.org/document/8708754
float IntegralMethod::_2rd_Adam_BashForth_Moulton(float X, float DT) {
	float FX;
	FX += ((((3 * X) - _2rd_ABM.X_1) / 2) * DT) + _2rd_ABM.FX_1;
	_2rd_ABM.FX_1 = FX;
	_2rd_ABM.X_2 = _2rd_ABM.X_1;
	_2rd_ABM.X_1 = X;

	return FX;
}

// Reference : https://ieeexplore.ieee.org/document/8708754
float IntegralMethod::_3rd_Adam_BashForth_Moulton(float X, float DT) {
	float FX;
	FX = ((((23 * X) - (16 * _3rd_ABM.X_1) + (5 * _3rd_ABM.X_2)) / 12) * DT)
			+ _3rd_ABM.FX_1;
	_3rd_ABM.FX_1 = FX;
	_3rd_ABM.X_2 = _Simpsons_1_3.X_1;
	_3rd_ABM.X_1 = X;
	return FX;
}

///Reset Accumulation Value (Optional)
void IntegralMethod::ResetStruct() {
	_Basic = reset;
	_Trapezoid = reset;
	_Simpsons_1_3 = reset;
	_Simpsons_3_8 = reset;
	_2rd_ABM = reset;
	_3rd_ABM = reset;
	_Boole = reset;
}

