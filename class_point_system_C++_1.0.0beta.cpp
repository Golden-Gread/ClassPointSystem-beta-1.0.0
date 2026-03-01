#include "./class_point_system_C++_1_0_0beta.h"   //point类头文件
#include "./class_point_system_classlist_C++_1_0_0beta.h"  //PointList类头文件
#include "./class_point_system_File_C++_1_0_0beta.h"  //PointFile类和RecordFile类头文件
#include"ClassPointSystemLoginC++1_0_0Beta.h"
//#include<windows.h>
//#include "resource.h"
#include <iostream>
#include <list>
#include <string>
#include <fstream>




//全局定义

PointList pl;
PointFile pf;
RecordFile rf;
LogFile lf;



using namespace std;

//函数定义

void load_point_list(PointList List,list<string> recordList){
    for(auto it = recordList.begin(); it!= recordList.end(); it++){
        int idx = it->find(",");
        string name = it->substr(0, idx);
        pl.add_record(name, *it);
    }
}


void save_point_list(PointList List){
    list<point> DataList = List.return_data();
    
    for (auto it = DataList.begin(); it!= DataList.end(); it++){
        list<point> plist;
        plist.emplace_back(point(it->print_point(), it->get_name()));
        list<string> recordList = it->get_record();
        pf.write_point(plist);
        rf.write_record(recordList);
    }
}

void adding_point(string name,int point_value){
	pl.change_point(name,point_value);
}




//窗口编译区


//代码测试区

int test(){
	lf.set_fliename("logfile.log");
	lf.write("--------------------------------------------");
	
	lf.write_log("[class point system C++1.0.0beta.cpp  test()][Info] system started.");
    pf.set_filename("d:/class point system-beta3.0.0 for C++/points.txt");
    list<point> pointlist = pf.read_point();
    list<point> list1 = {point(1, "p1"), point(2, "p2"), point(3, "p3")};
    pf.write_point(list1);
    point p(1, "p1");
    pl.add_point(p);
    pl.change_point("p1", 2);
	pl.change_point("pu",0);
	
    int n = pl.print_point("p1");
    cout << n << endl;
    for(auto it = pointlist.begin(); it!= pointlist.end(); it++){
        cout << it->get_name() << " " << it->print_point() << endl;
    }
    return 0;
}


int main(){
    return test();
}
