#include <bits/stdc++.h>
#include "db.h"
using namespace std;

void db::init(){
	//Do your db initialization.
}

void db::setTempFileDir(string dir){
	//All the files that created by your program should be located under this directory.
	database = dir + "/database";
	index = dir + "/index";
	return;
}

void db::import(string csvFileName){
	//Inport a csv file to your database.
	FILE* data = fopen(csvFileName.c_str(), "r");
	FILE* db = fopen(database.c_str(), "a+");
	// Ignore first line
	char tmp[666];
	fgets(tmp,666,data);
	char st[666];
	while(fgets(st,666,data))
	{
		int ord = 0;
		int cma_cnt = 0;
		while(cma_cnt < 14)
		{
			if(st[ord] == ',') ++cma_cnt;
			++ord;
		}
		while(true)
		{
			fputc(st[ord],db);
			if(st[ord] == ',') break;
			++ord;
		}
		++ord;
		while(st[ord] != ',')
			++ord;
		++ord;
		cma_cnt = 0;
		while(true)
		{
			if(st[ord] == ',') ++cma_cnt;
			if(cma_cnt >= 2) break;
			fputc(st[ord],db);
			++ord;
		}
		fputc('\n',db);
	}
	fclose(data);
	fclose(db);
	return;
}

void db::createIndex(){
	//Create index.
}

double db::query(string origin, string dest){
	//Do the query and return the average ArrDelay of flights from origin to dest.
	//This method will be called multiple times.
	FILE* db = fopen(database.c_str(),"r");
	return 0; //Remember to return your result.
}

void db::cleanup(){
	//Release memory, close files and anything you should do to clean up your db class.
	char* tmp = &database[0];
	remove(tmp);
}