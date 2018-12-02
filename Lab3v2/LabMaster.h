#pragma once
#include "point.h"

void findcenter(float&,float&,float,float,float,float,float,float);

const int ndots = 3;
const int dots[ndots * 2] = {
	/*0*/					200,100,
	/*1*/					550,850,
	/*2*/					250,450,
	///*3*/					100,350,
	///*4*/					900,650,
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


	point raven[ndots*ndots];
	int map[ndots*ndots][3];
	bool checkmap[ndots];
	int nraven = 0;
	point arr[ndots + 1];

	point floorlvl;
};

