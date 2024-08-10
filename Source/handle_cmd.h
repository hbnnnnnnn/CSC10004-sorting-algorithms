#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>


#include "DataGenerator.cpp"
#include "sort_headers.h"

#define ERROR -1

const std::string sortName[] = {
    "Selection Sort", "Selection Sort Improved", "Insertion Sort", "Insertion Sort Binary",
    "Bubble Sort", "Bubble Sort Improved", "Shaker Sort", "Shell Sort", "Heap Sort",
    "Merge Sort", "Merge Sort Improved", "Quick Sort", "Quick Sort Improved",
    "Counting Sort", "Radix Sort", "Radix Sort Improved", "Flash Sort"
};

const std::string dataTypeName[] = {
    "Randomize", "Nearly Sorted", "Sorted", "Reversed"
};

const int maxN = 1e6;
int a[maxN];
int data[maxN];

void executeSort(int a[], int inputSize, int sortFunction);
void executeSort(int a[], int inputSize, int sortFunction, long long &comparisions);
int GetSortName(const std::string &sortName);
int GetDataType(const std::string &dataType);
void CopyArray(int u[], int v[], int inputSize);
void PrintRunTime(int a[], int inputSize, int sortFunction, bool isCompare);
void PrintComparisons(int a[], int inputSize, int sortFunction, bool isCompare);
void PrintArray(int a[], int inputSize, const std::string fileName);
void GetInputData(int inputData[], int &inputSize, const std::string fileName);
void AlgorithmMode(int argc, char **argv);
void ComparisionMode(int argc, char **argv);