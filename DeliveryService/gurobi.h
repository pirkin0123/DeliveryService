#pragma once
#include "defines.h"
#include <array>

class Gurobi
{
public:
	Gurobi();
	~Gurobi();

	void read();
	void start();
	void test() const;

private:
	bool _read_var_cost(const std::string& input_cost_varcost);
	bool _read_outsourcing_cost(const std::string & input_cost_outsourcing17);
	bool _read_traveltime(const std::string& input_traveltime);
	bool _read_d1(const std::string& input_demand_task_collection, const std::string& input_demand_task_sending);
	bool _read_d2(const std::string& input_demand_transfer);
	bool _read_d3(const std::string& input_demand_transfer_majorcoutomer);
	bool _read_num_x1(const std::string& x1);
	bool _read_num_y1(const std::string& y1);
	bool _read_num_v1(const std::string& v1);
	bool _read_num_v2(const std::string& v2);
	bool _read_num_v3(const std::string& v3);
	void _generate_stochastic_parameter();
	void _generate_stochastic_demand();


	/*cost*/
	std::array<std::array<double, TASK>, DISTRICT> _c1; // c1[j][k] monthly cost of self truck   (file: input_cost_varcost)
	std::array<std::array<double, TASK>, DISTRICT> _c2; // c2=c1*2.5 (stochastic cost)
	std::array<std::array<double, TASK>, DISTRICT> _b1; // monthlycost of outsourcing 17 truck   (file: input_cost_outsourcing17)
	std::array<std::array<double, TASK>, DISTRICT> _b2; // b1*2 (stochastic cost)
	std::array<std::array<double, TASK>, DISTRICT> _a1; // monthly cost of outsourcing container truck   (b1*1.45)



	/* stochastic cost */
	std::array<double, STATION> _c3;
	std::array<double, STATION> _b4;
	std::array<double, TASK> _c4;
	std::array<double, TASK> _b6;
	std::array<double, STATION> _a2; // monthly cost of outsourcing container truck to another transshipment center  
	std::array<double, TASK> _a3;    // 外包貨櫃車配送大型客戶 之任務 k 一趟次之費用

	/* capacity*/
	std::array<double, TRUCK> _load;  // 17ton&container的容量


	/*travel time*/
	std::array<std::array<double, TASK>, DISTRICT> _u1; // travel time and operating time for serving district j and task k  (file:input_traveltime)
	std::array<double, STATION> _u2;                    // travel time and operating time for serving another transshipment center m    
	std::array<double, 1> _u3;                          // travel time and operating time for serving task k for major customer


	/* 運量*/
	std::array<std::array<std::array<std::array<double, TASK>, DISTRICT>, DAY>, SCENARIO> _d1; //在scenerio s下,第 t day, 區域j中,任務k的配送量 
	std::array<std::array<std::array<double, STATION>, DAY>, SCENARIO> _d2; // 在scenerio s下,第 t day,與其他轉運中心m的配送量
	std::array<std::array<std::array<double, TASK>, DAY>, SCENARIO> _d3;    // 在scenerio s下,第 t day,大客戶任務k的配送量

	/*產生隨機需求*/
	std::array < std::array<double, TASK>, DISTRICT> _sum_task_demand;  //district task
	std::array<std::array<double, TASK>, DISTRICT> _mean_task_demand;
	std::array<std::array<double, TASK>, DISTRICT> _std_task_demand;

	std::array<double, TASK> _sum_transfer_majorcustomer;
	std::array<double, TASK> _mean_transfer_majorcustomer;
	std::array<double, TASK> _std_transfer_majorcustomer;

	std::array<double, STATION> _sum_transfer_demand;
	std::array<double, STATION> _mean_transfer_demand;
	std::array<double, STATION> _std_transfer_demand;


	std::array<double, 1> _pro;

	/*50組隨機需求下，月趟次(x1,y1,v1,v2,v3) use other model to generate(totally have 50 set)*/

	std::array<std::array<std::array<std::array<std::array<int, TASK>, FLEET>, DISTRICT>, DAY>, SCENARIO> _num_x1; // (file:X1)
	std::array<std::array<std::array<std::array<int, TASK>, DISTRICT>, DAY>, SCENARIO> _num_y1;                    // (file:Y1)
	std::array<std::array<std::array<std::array<int, TASK>, DISTRICT>, DAY>, SCENARIO> _num_v1;                    // (file:V1)
	std::array<std::array<std::array<std::array<int, CAR_TYPE>, STATION>, DAY>, SCENARIO> _num_v2;                 // (file:v2)
	std::array<std::array<std::array<int, TASK>, DAY >, SCENARIO> _num_v3;                                         // (file:v3)

};