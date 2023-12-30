// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Shanon Reckinger
// U. of Illinois, Chicago
// CS 251: Fall 2021
//

/*
* Project 3 - Animated Bar Chart
* Date: 2/22/22
* Manh Vu Bui
* vub2
*
* Creative component: added variables begin, end to
* change begin and starting point.
*	I also added multiples helper function in
* barchartanimate.h and barchart.h to help with this feature.
*
* Regardings what they do, the interface itself is pretty straightfoward.
* Thanks.
* Vu
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;

void loadData(ifstream& inFile, string& title,
	string& xlabel, string& source) {

	cout << "Please enter the data file name: ";
	string filename;
	cin >> filename;

	inFile.open(filename);

	if (!inFile.is_open()) {
		cout << "File not found" << endl;
		loadData(inFile, title, xlabel, source);
		return;
	}

	getline(inFile, title);
	getline(inFile, xlabel);
	getline(inFile, source);
}

void menu(char& c) {
	cout << "1. Animate Data" << endl;
	cout << "2. Change starting point" << endl;
	cout << "3. Change ending point" << endl;
	cout << "4. Display specific frame" << endl;
	cout << "5. Change Data File" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter option number: ";
	cin >> c;
}

void displayFrame(BarChartAnimate& bca) {
	cout << "Enter frame to display ";
	cout << "from 0 (" << bca[0].getFrame();
	cout << ") to " << bca.getSize() - 1 << " (";
	cout << bca[bca.getSize() - 1].getFrame() << "): ";
	int frame;
	cin >> frame;
	if (frame >= bca.getSize()) {
		cout << "Invalid frame" << endl;
		return;
	}
	bca.setBegin(frame);
	bca.setEnd(-1);
	bca.animate(cout, 12, frame + 1);
	bca.setBegin(0);
}

void process(char& c, BarChartAnimate& bca) {
	int begin = 0;
	int end = -1;
	switch (c)
	{
	case '1':
		bca.animate(cout, 12, 20);
		break;
	case '2':
		cout << "Enter starting point (min 0): ";
		cin >> begin;
		bca.setBegin(begin);
		break;
	case '3':
		cout << "Enter ending point (max " << bca.getSize() - 1;
		cout << " or -1 for default): ";
		cin >> end;
		bca.setEnd(end);
		break;
	case '4':
		displayFrame(bca);
		break;
	default:
		break;
	}
}

void loadData2(ifstream& inFile, BarChartAnimate& bca) {
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
}

int main() {
	cout << "Welcome to Data Animation." << endl;
	string title, xlabel, source;
	char c = ' ';
	while (c != '0') {
		ifstream inFile;
		loadData(inFile, title, xlabel, source);
		BarChartAnimate bca(title, xlabel, source);
		loadData2(inFile, bca);
		c = ' ';
		while (c != '5' && c != '0') {
			menu(c);
			process(c, bca);
		}
	}

	return 0;
}


/*#include <iostream>
#include "barchartanimate.h"
using namespace std;


bool testBarDefaultConstructor() {
	Bar b;
	if (b.getName() != "") {
		cout << "testBarDefaultConstructor: getName failed" << endl;
		return false;
	}
	else if (b.getValue() != 0) {
		cout << "testBarDefaultConstructor: getValue failed" << endl;
		return false;
	}
	else if (b.getCategory() != "") {
		cout << "testBarDefaultConstructor: getCategory failed" << endl;
		return false;
	}
	cout << "testBarDefaultConstructor: all passed!" << endl;
	return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
	if (b.getName() != "Chicago") {
		cout << "testBarParamConstructor: getName failed" << endl;
		return false;
	}
	else if (b.getValue() != 9234324) {
		cout << "testBarParamConstructor: getValue failed" << endl;
		return false;
	}
	else if (b.getCategory() != "US") {
		cout << "testBarParamConstructor: getCategory failed" << endl;
		return false;
	}
	cout << "testBarParamConstructor: all passed!" << endl;
	return true;
}

bool testBarOverloadedOperator() {
	Bar b1("Chicago", 9234324, "US");
	Bar b2("LA", 12, "US");
	Bar b3("SF", 9234324, "UK");
	if (b1 < b2) {
		cout << "testBarOverloadedOperator: operator< failed" << endl;
		return false;
	}
	else if (b1 < b3) {
		cout << "testBarOverloadedOperator: operator>= failed" << endl;
		return false;
	}
	else if (b2 > b3) {
		cout << "testBarOverloadedOperator: operator> failed" << endl;
		return false;
	}
	cout << "testBarOverloadedOperator: all passed!" << endl;
	return true;
}

bool testBarChartDefaultConstructor() {
	BarChart newBar;
	if (newBar.getFrame() != "") {
		cout << "testBarChartDefaultConstructor: getFrame failed" << endl;
		return false;
	}
	else if (newBar.getSize() != 0) {
		cout << "testBarChartDefaultConstructor: getSize failed" << endl;
		return false;
	}
	cout << "testBarChartDefaultConstructor: all passed!" << endl;
	return true;
}

bool testBarChartParamConstructor() {
	BarChart newBar(5);
	if (newBar.getFrame() != "") {
		cout << "testBarChartParamConstructor: getFrame failed" << endl;
		return false;
	}
	else if (newBar.getSize() != 0) {
		cout << "testBarChartParamConstructor: getSize failed" << endl;
		return false;
	}
	cout << "testBarChartParamConstructor: all passed!" << endl;
	return true;
}

bool testBarChartCopyConstructor() {
	BarChart bar1(1);
	bar1.addBar("", 1, "");
	bar1.setFrame("frame");
	BarChart bar2(bar1);
	if (bar2.getSize() != 1) {
		cout << "testBarChartCopyConstructor: getSize failed" << endl;
		return false;
	}
	else if (bar2.getFrame() != "frame") {
		cout << "testBarChartCopyConstructor: getFrame failed" << endl;
		return false;
	}
	cout << "testBarChartCopyConstructor: all passed!" << endl;
	return true;
}

bool testBarChartCopyOperator() {
	BarChart bar1(1);
	bar1.addBar("", 1, "");
	bar1.setFrame("frame");
	BarChart bar2 = bar1;
	if (bar2.getSize() != 1) {
		cout << "testBarChartCopyOperator: getSize failed" << endl;
		return false;
	}
	else if (bar2.getFrame() != "frame") {
		cout << "testBarChartCopyOperator: getFrame failed" << endl;
		return false;
	}
	cout << "testBarChartCopyOperator: all passed!" << endl;
	return true;
}

bool testBarChartClear() {
	BarChart bar1(1);
	bar1.addBar("", 1, "");
	bar1.clear();
	if (bar1.getSize() != 0) {
		cout << "testBarChartClear: getSize failed" << endl;
		return false;
	}
	cout << "testBarChartClear: all passed!" << endl;
	return true;
}

bool testBarChartSetFrame() {
	BarChart bar1;
	bar1.setFrame("frame");
	if (bar1.getFrame() != "frame") {
		cout << "testBatChartSetFrame: getFrame failed" << endl;
		return false;
	}
	cout << "testBarChartSetFrame: all passed!" << endl;
	return true;
}

bool testBarChartAtOperator() {
	BarChart bar1(2);
	bar1.addBar("LA", 1, "UK");
	bar1.addBar("Chicago", 9234324, "US");
	if (bar1[1].getName() != "Chicago") {
		cout << "testBarChartAtOperator: getName failed" << endl;
		return false;
	}
	else if (bar1[1].getValue() != 9234324) {
		cout << "testBarChartAtOperator: getValue failed" << endl;
		return false;
	}
	else if (bar1[1].getCategory() != "US") {
		cout << "testBarChartAtOperator: getCategory failed" << endl;
		return false;
	}
	cout << "testBarChartAtOperator: all passed!" << endl;
	return true;
}

bool testBCAParamConstructor() {
	BarChartAnimate bca("titlex", "labelx", "sourcex");
	if (bca.getSize() != 0) {
		cout << "testBCAParamConstructor: getSize failed" << endl;
	}
	cout << "testBCAParamConstructor: all passed!" << endl;
	return true;
}

bool testBCAaddFrame() {
	BarChartAnimate bca("titlex", "labelx", "sourcex");
	ifstream infile("cities.txt");
	for (int i = 0; i < 3; i++) {
		string line;
		getline(infile, line);
	}
	while (!infile.eof()) {
		bca.addFrame(infile);
	}

	if (bca.getSize() != 519) {
		cout << "testBCAaddFrame: getSize failed" << endl;
		return false;
	}
	cout << "testBCAaddFrame: all passed!" << endl;
	return true;
}

bool testBCAatOperator() {
	BarChartAnimate bca("titlex", "labelx", "sourcex");
	ifstream infile("cities.txt");
	for (int i = 0; i < 3; i++) {
		string line;
		getline(infile, line);
	}
	while (!infile.eof()) {
		bca.addFrame(infile);
	}
	
	if (bca[0].getSize() != 12) {
		cout << "testBCAatOperator: getSize failed" << endl;
		return false;
	}
	cout << "testBCAatOperator: all passed!" << endl;
	return true;
}



int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();
	testBarOverloadedOperator();

	testBarChartDefaultConstructor();
	testBarChartParamConstructor();
	testBarChartCopyConstructor();
	testBarChartCopyOperator();
	testBarChartClear();
	testBarChartSetFrame();
	testBarChartAtOperator();

	testBCAParamConstructor();
	testBCAaddFrame();
	testBCAatOperator();

	return 0;
}
*/