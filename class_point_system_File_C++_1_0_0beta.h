#ifndef POINTFILE_H
#define POINTFILE_H



#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <filesystem>
#include "class_point_system_C++_1_0_0beta.h"
#include "ClassPointSystemLoginC++1_0_0Beta.h"
typedef pair<string,string> setting;



using namespace std;
namespace fs = std::filesystem;
using namespace fs;




class PointFile{
    private:
        string filename;
		LogFile lf;
    public:
        void set_filename(string filename);
        list<point> read_point();
        void write_point(list<point> plist);
		PointFile():filename(""){lf.set_fliename("logfile.log");}
	

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
	LogFile lf;
public:
	void set_filename(string filename);
	list<string> read_record();
	void write_record(list<string> rlist);
	RecordFile():filename(""){lf.set_fliename("logfile.log");}
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






class ConfitFile{
private:
	string filepath="";
	list<setting> settings_list={};
	LogFile lf;
public:
	void loading_settings();
	void saving_settings();
	pair<bool,string> searching_settings(string setting_name);
	void changeing_setting(setting settings);
	void setting_filepath(string path);
	ConfitFile():filepath(""){lf.set_fliename("logfile.log");}
	
};

inline void ConfitFile::loading_settings(){
	settings_list.clear();
	setting s;
	
	ifstream confit;string setting_string="";
	if(exists(filepath)){
		confit.open(filepath);
		while(getline(confit,setting_string)){
			s.first=setting_string.substr(0,(int)setting_string.find(':'));
			s.second=setting_string.substr(setting_string.find(':'));
			settings_list.push_back(s);
		}
	}
	else{
		cout << "File not found" << endl;
		lf.write_log("[<File.h> ConfitFile::loading_setting][Warning] ConfitFile was not found.");
	}
	
	
}

inline void ConfitFile::saving_settings(){
	ofstream confit;
	confit.open(filepath);
	
	for(auto it=settings_list.begin();it!=settings_list.end();it++){
		confit<<it->first<<":"<<it->second<<endl;
	}
	
	
}


#endif
