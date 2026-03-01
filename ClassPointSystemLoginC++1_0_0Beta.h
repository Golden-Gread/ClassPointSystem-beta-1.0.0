#ifndef CLASSPOINTSYSTEMLOGINC_1_0_0BETA_H
#define CLASSPOINTSYSTEMLOGINC_1_0_0BETA_H


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>


using namespace std;


class Time{
private:
	
public:
	string get_time(){
		time_t now=time(nullptr);
		tm* timeinfo = localtime(&now);
		char buffer[100];
		strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M:%S", timeinfo);
		return string(buffer);
	}
};

Time system_time;




class LogFile{
    private:
        string filename;
    public:
        void set_fliename(string filepath);
        void write_log(string login);
		void write(string s);

};


inline void LogFile::set_fliename(string filepath){
    filename = filepath;
}


inline void LogFile::write_log(string login){
	//time_t now = time(nullptr);
	//tm* timeinfo = localtime(&now);
	
	//strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M:%S", timeinfo);
	
	
	
    ofstream wf;
    wf.open(filename,ios::app);
    wf <<"["<<system_time.get_time()<<"]"<< login << endl;
    wf.close();
}

inline void LogFile::write(string s){
	ofstream wf;
	wf.open(filename,ios::app);
	wf<<s<<endl;
	wf.close();
	
}

#endif
