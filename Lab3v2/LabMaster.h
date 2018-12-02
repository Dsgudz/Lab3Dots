#pragma once
#include "point.h"

void findcenter(float&,float&,float,float,float,float,float,float);

const int ndots = 5;
const int dots[ndots * 2] = {
	/*0*/					550,550,
	/*1*/					560,590,
	/*2*/					750,600,
	/*3*/					700,350,
	/*4*/					800,650,
	///*5*/					350,550,
	///*6*/					600,200,
	///*7*/					850,900,
	///*8*/					650,400,
	///*9*/					400,800,
							};



class LabMaster
{
public:
	LabMaster();

	void start();

	void sort();
	void fortune();
	void voronoy();


	point raven[ndots*ndots];
	int map[ndots*ndots][3];
	bool checkmap[ndots];
	int nraven = 0;
	point arr[ndots + 1];

	point floorlvl;
};

