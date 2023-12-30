#include <iostream>
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
