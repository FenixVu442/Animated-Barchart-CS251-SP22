/*
* File: barchartanimate.h
* Project 3 - Animated Bar Chart
* Date: 02/17/2022
* Manh Vu Bui
* vub2
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
// #include <unistd.h>
#include "myrandom.h" // used in autograder, do not remove
#include "barchart.h"

using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    long unsigned int colorItr;

    string title = "";
    string xlabel = "";
    string source = "";

    int begin = 0; // creative component
    int end = -1; // creative component

    // expand:
    // this is a helper function that expand
    // barcharts capacity when the current 
    // capacity is no longer sufficient
    void expand() {
        int newCap = 2 * capacity;
        BarChart* newCharts = new BarChart[newCap];

        for (int i = 0; i < size; i++) {
            newCharts[i] = barcharts[i];
        }

        delete[] barcharts;
        barcharts = newCharts;
        capacity = newCap;
    }

    void mapColor(string category) {
        if (colorMap.count(category) == 0) {
            colorMap[category] = COLORS[colorItr];
            // cout << COLORS[colorItr] << category << endl;
            colorItr++;
        }
        if (colorItr == COLORS.size()) {
            colorItr = 0;
        }
    }

public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        barcharts = new BarChart[4];
        size = 0;
        capacity = 4;

        this->title = title;
        this->xlabel = xlabel;
        this->source = source;

        colorItr = 0;
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        if (barcharts != nullptr) delete[] barcharts;
    }

    // extract:
    // helper function that basically do samething as getline.
    // It is created to compact addFrame
    string extract(stringstream& ss, char c) {
        string line;
        getline(ss, line, c);
        return line;
    }

    string extract(stringstream& ss) {
        string line;
        getline(ss, line);
        return line;
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream& infile) {
        if (size == capacity) expand();

        string line = "";
        int length = 0;

        while (line.size() == 0) { // to get rid of empty line
            getline(infile, line);
            if (infile.fail()) return;
        }

        length = stoi(line);
        BarChart newBar(length);

        getline(infile, line);
        while (line.size() != 0) {
            stringstream ss(line);
            string name, category, country;
            int value;

            newBar.setFrame(extract(ss, ','));
            name = extract(ss, ',');
            country = extract(ss, ',');
            value = stoi(extract(ss, ','));
            category = extract(ss);

            mapColor(category);

            newBar.addBar(name, value, category);
            newBar.front().setCountry(country);

            // Finish one line, go to next line
            getline(infile, line);
        }

        barcharts[size] = newBar;
        size++;
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
    void animate(ostream& output, int top, int endIter) {
        unsigned int microsecond = 50000;

        if (end != -1) endIter = end + 1; // creative component

        if (endIter < 0 || endIter > size) endIter = size;

        for (int i = begin; i < endIter; i++) {
            // usleep(3 * microsecond);
            cin.get();
            output << CLEARCONSOLE;
            output << BLACK << title << endl;
            output << source << endl;
            barcharts[i].graph(output, colorMap, top);
            output << BLACK << xlabel << endl;
            output << "Frame: " << barcharts[i].getFrame() << endl;
        }
    }

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize() {
        return size;
    }

    // creative component
    // setBegin:
    // set starting point to begin
    void setBegin(int begin) {
        this->begin = begin;
    }

    // creative component
    // setEnd:
    // set ending point to end
    void setEnd(int end) {
        this->end = end;
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i) {
        if (i < 0 || i > size) {
            throw out_of_range("BarChart: i out of bounds");
        }

        return barcharts[i];
    }
};
