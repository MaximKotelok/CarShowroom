#pragma once
#include <iostream>

using namespace std;

class NotFoundException : public exception{
	int id;
public:
	NotFoundException(const char* m, int id) :exception(m) {
		this->id = id;
	}

	int get_id() {
		return id;
	}

};

class FileNotOpenException :public exception {
	string path;
public:
	FileNotOpenException(const char* m, string path) :exception(m) {
		this->path = path;
	}

	string get_path() {
		return path;
	}

};
