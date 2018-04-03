#include "defines.h"
#include <array>

#pragma once

class Gurobi
{
public:
	Gurobi();
	~Gurobi();

	void read();

private:
	void _read_cost();
	
	/*cost*/
	//double c1[district][task]; // c1[j][k] monthly cost of self truck   (file: input_cost_varcost)
	std::array<std::array<double, district>, task> _c1;
	std::array<std::array<double, district>, task> _c2;
	//double b1[district + 1][task + 1];// monthlycost of outsourcing 17 truck   (file: input_cost_outsourcing17)
	//double a1[district + 1][task + 1];// monthly cost of outsourcing container truck   (b1*1.45)

									  //stochastic cost
	//double c2[district + 1][task + 1];//c2=c1*2.5
	/*double b2[district + 1][task + 1];//b1*2
	double c3[station + 1] = { 0, 27500, 51500 };
	double b4[station + 1] = { 0, 11000, 20600 };
	double c4[task + 1] = { 0, 21500, 21500 };
	double b6[task + 1] = { 0, 8600, 8600 };
	double a2[station + 1] = { 0, 8000, 15000 }; // monthly cost of outsourcing container truck to another transshipment center  
	double a3[task + 1] = { 0, 6200, 6200 };       // �~�]�f�d���t�e�j���Ȥ� ������ k �@�릸���O��
	*/

												   /* capacity*/
	//double load[truck + 1] = { 0, 14, 20 }; //17ton&container���e�q

											/*travel time*/
	//double u1[district + 1][task + 1]; // travel time and operating time for serving district j and task k
	//double u2[station + 1] = { 0, 2, 4 }; //travel time and operating time for serving another transshipment center m    
	//double u3 = 1.11; // travel time and operating time for serving task k for major customer

					  /* �B�q*/
	//static int d1[scenario + 1][day + 1][district + 1][task + 1]; //�bscenerio s�U,�� t day, �ϰ�j��,����k���t�e�q 
	//static int d2[scenario + 1][day + 1][station + 1]; // �bscenerio s�U,�� t day,�P��L��B����m���t�e�q
	//static int d3[scenario + 1][day + 1][task + 1]; // �bscenerio s�U,�� t day,�j�Ȥ����k���t�e�q 
};

