#include "mockos/TextFile.h"
#include <string>
#include <iostream>
#include <vector>
#include "mockos/AbstractFileVisitor.h"
using namespace std;

TextFile::TextFile(string n) {
	this->name = n;
}

unsigned int TextFile::getSize() {
	return contents.size();
}

string TextFile::getName() {
	return name;
}

int TextFile::write(vector<char> v) {
	contents = v;
	return 0; // success
}

int TextFile::append(vector<char> v) {
	for (int i = 0; i < v.size(); i++) {
		contents.push_back(v[i]);
	}
	return 0; // success
}

vector<char> TextFile::read() {
	return contents;
}

void TextFile::accept(AbstractFileVisitor* afv) {
	afv->visit_TextFile(this);
}


