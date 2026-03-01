#ifndef POINTLIST_H
#define POINTLIST_H



#include <list>
#include <string>
#include "./class_point_system_File_C++_1_0_0beta.h"
#include "./class_point_system_C++_1_0_0beta.h"
#include "./ClassPointSystemLoginC++1_0_0Beta.h"
#include <algorithm>

using namespace std;






class PointList{
    private:
        list<point> plist;
		LogFile lf;
	
    public:
		
		void restart(){lf.set_fliename("logfile.log");}
        void add_point(point p);
        void remove_point(string n);
        void change_point(string n, int d);
        int print_point(string n);
        void restart_point();
        int length();
        void add_record(string n, string r);
        list<string> get_record(string n);
        list<string> get_name(int i);
        bool is_exist(string n);
        int max_point();
        int min_point();
        list<point> return_data();
		PointList() : plist({}) {restart();}
	
	



};


inline int PointList::max_point(){
    list<int> data_list = {};
    for(auto it = plist.begin();it != plist.end(); ++it){
        data_list.push_back(it->point::print_point());

    }

    auto max_it = max_element(data_list.begin(), data_list.end());
    if (max_it != data_list.end()){
        lf.LogFile::write_log("[<classslist.h> PointList::max_point][Info] Finding max point competely. The max point is "+to_string(*max_it));
        return *max_it;
    }
    else{
        lf.LogFile::write_log("[<classlist.h> PointList::max_point][Warning] The list named \'plist\' is empty.");
        return INT_MIN;   // 错误返回值
    }

}


inline int PointList::min_point(){
    list<int> data_list = {};
    for(auto it = plist.begin();it != plist.end(); ++it){
        data_list.push_back(it->point::print_point());
    }
    auto min_it = min_element(data_list.begin(), data_list.end());
    if (min_it != data_list.end()){
        lf.LogFile::write_log("[<classlist.h> PointList::min_point][Info] Finding min point competely. The min point is " + to_string(*min_it));
        return *min_it;
        }
    else{
        lf.LogFile::write_log("[<classlist.h> PointList::min_point][Warning] The list named \'plist\' is empty.");
        return INT_MAX;   // 错误返回值
    }
}




inline bool PointList::is_exist(string n){
    for(auto it = plist.begin();it != plist.end(); ++it){
        if (it->point::get_name() == n){
            lf.LogFile::write_log("[<classlist.h> PointList::is_exist][Info] Searching " + n +" competely");
            return true;
        }
    }
    lf.LogFile::write_log("[<classlist.h> PointList::is_exist][Info] Searching " + n +"failed. The name is not existed");
    return false;
}





inline void PointList::add_point(point p){
    lf.LogFile::write_log("[<classlist.h> PointList::add_point][Info] Adding point competely.");
    plist.push_back(p);
}

inline void PointList::remove_point(string n){
    if (is_exist(n)){
        for(auto it = plist.begin();it != plist.end(); ++it){
            if (it->point::get_name() == n){
                plist.erase(it);
                lf.LogFile::write_log("[<classlist.h> PointList::remove_point][Info] Removing point competely.");
                break;
            }
        }
    }
    else{
        lf.LogFile::write_log("[<classlist.h> PointList::remove_point][Warning] Removing point filed. Because this name:"+n+" is not existed");
    }


}

inline void PointList::change_point(string n, int d){
    if (is_exist(n)){
        for(auto it = plist.begin();it != plist.end(); ++it){
            if (it->point::get_name() == n){
                it->point::change_point(d);
                lf.LogFile::write_log("[<classlist.h> PointList::change_point][Info] Changing "+n+"\'s point data competely.");
                break;
            }
        }
    }
    else{
        cout << "Point not found" << endl;
        lf.LogFile::write_log("[<classlist.h> PointList::change_point][Warning] Do not find point.");
    }
}

inline int PointList::print_point(string n){
    if (is_exist(n)){
        for(auto it = plist.begin();it != plist.end(); ++it){
            if (it->point::get_name() == n){
                lf.LogFile::write_log("[<classlist.h> PointList::print_point][Info] Printting point competely.");
                return it->point::print_point();
            }
        }
    }
    else{
        cout << "Point not found" << endl;
        lf.LogFile::write_log("[<classlist.h> PointList::print_point][Warning] Do not find point");
        return -404;
    }
}

inline void PointList::restart_point(){
    for(auto it = plist.begin();it != plist.end(); ++it){
        it->point::restart_point();
        lf.write_log("[<classlist.h> PointList::restart_point][Info] Restarting point competely");
    }
}

inline int PointList::length(){
    int count = 0;
    for(auto it = plist.begin();it != plist.end(); ++it){
        count++;
    }
    return count;

}


inline void PointList::add_record(string n, string r){
    if (is_exist(n)){
        for(auto it = plist.begin();it != plist.end(); ++it){
            if (it->point::get_name() == n){
                it->point::add_record(r);
                break;
            }
        }
    }
    else{
        cout << "Point not found" << endl;
    }
}


inline list<string> PointList::get_record(string n){
    if (is_exist(n)){
        for(auto it = plist.begin();it != plist.end(); ++it){
            if (it->point::get_name() == n){
                return it->point::get_record();
            }
        }
    }
    else{
        list<string> empty_list = {"Error"};
        cout << "Point not found" << endl;
        return empty_list;
    }
}


inline list<string> PointList::get_name(int i){
    if (i < min_point() || i > max_point()){
        list<string> empty_list = {"Error"};
        cout << "Index out of range" << endl;
        return empty_list;
        }
    else{
        list<string> name_list = {};
        for(auto it = plist.begin();it != plist.end(); ++it){
            if (it->point::print_point() == i){
                name_list.push_back(it->point::get_name());
            }
        }
        return name_list;
    }
}

inline list<point> PointList::return_data(){
    return plist;
}


#endif
