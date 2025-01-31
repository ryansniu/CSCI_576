#pragma once

#include <vector>
#include <string>
#include <tuple>
#include <cmath>
#include <iostream>
#include <fstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

using namespace std;
class DominantColorList
{
private:
	string srcVideo;
	int numUnusedHues;
	Mat firstFrame;

	vector<int*> validHues;
	int* dominantHues;

public:
	DominantColorList();
	void addDominantHue(vector<tuple<int, int>> dominantColors);

	int* getHueInformation() { return dominantHues; };

	vector<int*>* getHueVec() { return &validHues; };
	bool checkHueSpectrum(DominantColorList* subsample);
	int containsSubset(DominantColorList* subsample);
	bool checkIfValidSubset(int offset, vector<int*>* subsample);


	void dumpData(string fileInput);
	void populateDataHue(string fileInput);
	void populateDataVec(string fileInput);
	void setSrcVideo(string s) { srcVideo = s; };

	Mat findFirstFrame(int i);

	int getNumUnusedHues() { return numUnusedHues; };
	bool acceptableColorIndex(int i, DominantColorList* sample);
};

