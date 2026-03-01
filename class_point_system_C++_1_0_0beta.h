
#ifndef POINT_H
#define POINT_H



#include <iostream>
#include <cmath>
#include <string>
#include <list>
#include "ClassPointSystemLoginC++1_0_0Beta.h"


using namespace std;




class point{             
    private:
        int data;
        string name;
        list<string> record;
    public:
		LogFile lf;
		
        point(int d, string n):data(d),name(n){
			lf.set_fliename("logfile.log");
			lf.LogFile::write_log("[<point.h> point::point][Info] Create point data sucessfully");
			record.push_back(n+","+to_string(d)+system_time.get_time());
		};
        void change_point(int d);
        int print_point();
        string get_name();
        void restart_point();
        list<string> get_record();
        void add_record(string r);
};


inline void point::change_point(int d){
    data += d;
    lf.LogFile::write_log("[<point.h> point::change_point][Info] Changing point data sucessfully,value = "+to_string(data));
	record.push_back(name+","+to_string(d)+","+system_time.get_time());
	
}

inline int point::print_point(){
    return data;
}

inline string point::get_name(){
    return name;
}

inline void point::restart_point(){
    data = 0;
}

inline list<string> point::get_record(){
    return record;
}

inline void point::add_record(string r){
    record.push_back(r);
}





#endif
