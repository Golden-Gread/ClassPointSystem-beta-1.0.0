#ifndef POINTFILE_H
#define POINTFILE_H



#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <filesystem>
#include "class_point_system_C++_1_0_0beta.h"

using namespace std;
namespace fs = std::filesystem;
using namespace fs;




class PointFile{
    private:
        string filename;
    public:
        void set_filename(string filename);
        list<point> read_point();
        void write_point(list<point> plist);


};




inline void PointFile::set_filename(string filename){
    this->filename = filename;
}

inline list<point> PointFile::read_point(){
    list<point> plist;
    string line;
    ifstream rf;
    if (exists(filename)){
        rf.open(filename, ios::in);
        while (getline(rf, line)){
            string name, data;
            auto name_end = line.find(",");
            name = line.substr(0, name_end);
            data = line.substr(name_end+1);
            int d = stoi(data);
            point p(d, name);
            plist.push_back(p);
    }
    rf.close();
    return plist;
    }
    else{
        cout << "File not found" << endl;
        ifstream rf;
        ofstream tf;
        tf.open(filename, ios::out);
        tf.close();
        rf.open(filename, ios::in);
        while (getline(rf, line)){
            string name, data;
            auto name_end = line.find(",");
            name = line.substr(0, name_end);
            data = line.substr(name_end+1);
            int d = stoi(data);
            point p(d, name);
            plist.push_back(p);
    }
    rf.close();
    return plist;


    }

}



inline void PointFile::write_point(list<point> plist){
    ofstream wf;
    wf.open(filename, ios::out);
    for(auto it = plist.begin(); it!= plist.end(); it++){
        string wdata;
        wdata = it-> point::get_name() + "," + to_string(it->point::print_point());
        wf << wdata << endl;
    }
    wf.close();
}



//记录文件类

class RecordFile{
    private:
        string filename;
    public:
        void set_filename(string filename);
        list<string> read_record();
        void write_record(list<string> rlist);
};




inline void RecordFile::set_filename(string filename){
    this->filename = filename;
}

inline list<string> RecordFile::read_record(){
    list<string> rlist;
    string line;
    ifstream rf;
    if (exists(filename)){
        rf.open(filename, ios::in);
        while (getline(rf, line)){
            rlist.push_back(line);
        }
        rf.close();
        return rlist;
    }
    else{
        cout << "File not found" << endl;
        ifstream rf;
        ofstream tf;
        tf.open(filename, ios::out);
        tf.close();
        rf.open(filename, ios::in);
        while (getline(rf, line)){
            rlist.push_back(line);
        }
        rf.close();
        return rlist;
    }
}



inline void RecordFile::write_record(list<string> rlist){
    ofstream wf;
    wf.open(filename, ios::out);
    for (auto it = rlist.begin(); it!= rlist.end(); it++){
        wf << *it << endl;

    }
    wf.close();
}








#endif
