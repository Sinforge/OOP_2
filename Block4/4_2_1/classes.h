#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
using namespace std;

class CL_1 {
private:
	string name1;
public:
	CL_1(string name1) {
		this->name1 = name1 + "_1\n";
	}
	void get_name() {
		cout << name1;
	}

};

class CL_2 : virtual public CL_1 {
private:
	string name2;
public:
	CL_2(string name2):CL_1(name2) {
		this->name2 = name2 + "_2\n";
	}
	void get_name() {
		cout << name2;
	}

};
class CL_3 : virtual public CL_1 {
private:
	string name3;
public:
	CL_3(string name3):CL_1(name3) {
		this->name3 = name3 + "_3\n";
	}
	void get_name() {
		cout << name3;
	}

};
class CL_4 : virtual public CL_1 {
private:
	string name4;
public:
	CL_4 (string name4): CL_1(name4) {
		this->name4 = name4 + "_4\n";
	}
	void get_name() {
		cout << name4;
	}

};
class CL_5 : virtual public CL_1 {
private:
	string name5;
public:
	CL_5(string name5) : CL_1(name5) {
		this->name5 = name5 + "_5\n";
	}
	void get_name() {
		cout << name5;
	}

};
class CL_6 : public CL_2, public CL_3 {
private:
	string name6;
public:
	CL_6(string name6):  CL_2(name6),  CL_3(name6), CL_1(name6) {
		this->name6 = name6 + "_6\n";
	}
	void get_name() {
		cout << name6;
	}

};
class CL_7 : public CL_4, public CL_5 {
private:
	string name7;
public:
	CL_7(string name7): CL_4(name7),  CL_5(name7), CL_1(name7) {
		this->name7 = name7 + "_7\n";
	}
	void get_name() {
		cout << name7;
	}

};
class CL_8 : public CL_6, public CL_7 {
private:
	string name8;
public:
	CL_8(string name8):CL_6(name8), CL_7(name8), CL_1(name8) {
		this->name8 = name8 + "_8";
	}
	void get_name() {
		cout << name8;
	}

};

#endif
