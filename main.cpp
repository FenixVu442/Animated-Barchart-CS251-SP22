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
