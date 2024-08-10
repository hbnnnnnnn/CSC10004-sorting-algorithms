#include "handle_cmd.h"

void executeSort(int a[], int inputSize, int sortFunction) {
    switch (sortFunction) {
        case 0:
            selectionSort(a, inputSize);
            break;
        case 1:
            selectionSortImproved(a, inputSize);
            break;
        case 2:
            insertionSort(a, inputSize);
            break;
        case 3:
            binaryInsertionSort(a, inputSize);
            break;
        case 4:
            bubbleSort(a, inputSize);
            break;
        case 5:
            bubbleSortImproved(a, inputSize);
            break;
        case 6:
            shakerSort(a, inputSize);
            break;
        case 7:
            shellSort(a, inputSize);
            break;
        case 8:
            heapSort(a, inputSize);
            break;
        case 9:
            mergeSort(a, inputSize);
            break;
        case 10:
            mergeSortImproved(a, inputSize);
            break;
        case 11:
            quickSort(a, inputSize);
            break;
        case 12:
            quickSortImproved(a, inputSize);
            break;
        case 13:
            countingSort(a, inputSize);
            break;
        case 14:
            radixSort(a, inputSize);
            break;
        case 15:
            radixSortImproved(a, inputSize);
            break;
        case 16:
            flashSort(a, inputSize);
            break;
        default:
            break;
    }
}

void executeSort(int a[], int inputSize, int sortFunction, long long &comparisions) {
    switch (sortFunction) {
        case 0:
            selectionSort_cpr(a, inputSize, comparisions);
            break;
        case 1:
            selectionSortImproved_cpr(a, inputSize, comparisions);
            break;
        case 2:
            insertionSort_cpr(a, inputSize, comparisions);
            break;
        case 3:
            binaryInsertionSort_cpr(a, inputSize, comparisions);
            break;
        case 4:
            bubbleSort_cpr(a, inputSize, comparisions);
            break;
        case 5:
            bubbleSortImproved_cpr(a, inputSize, comparisions);
            break;
        case 6:
            shakerSort_cpr(a, inputSize, comparisions);
            break;
        case 7:
            shellSort_cpr(a, inputSize, comparisions);
            break;
        case 8:
            heapSort_cpr(a, inputSize, comparisions);
            break;
        case 9:
            mergeSort_cpr(a, inputSize, comparisions);
            break;
        case 10:
            mergeSortImproved_cpr(a, inputSize, comparisions);
            break;
        case 11:
            quickSort_cpr(a, inputSize, comparisions);
            break;
        case 12:
            quickSortImproved_cpr(a, inputSize, comparisions);
            break;
        case 13:
            countingSort_cpr(a, inputSize, comparisions);
            break;
        case 14:
            radixSort_cpr(a, inputSize, comparisions);
            break;
        case 15:
            radixSortImproved_cpr(a, inputSize, comparisions);
            break;
        case 16:
            flashSort_cpr(a, inputSize, comparisions);
            break;
        default:
            break;
    }
}

int GetSortName(const std::string &sortName) {
    if (sortName.size() <= 0) throw ERROR;

    if (sortName == "selection-sort") return 0;
    else if (sortName == "selection-sort-impove") return 1;
    else if (sortName == "insertion-sort") return 2;
    else if (sortName == "insertion-sort-binary") return 3;
    else if (sortName == "bubble-sort") return 4;
    else if (sortName == "bubble-sort-improve") return 5;
    else if (sortName == "shaker-sort") return 6;
    else if (sortName == "shell-sort") return 7;
    else if (sortName == "heap-sort") return 8;
    else if (sortName == "merge-sort") return 9;
    else if (sortName == "merge-sort-improve") return 10;
    else if (sortName == "quick-sort") return 11;
    else if (sortName == "quick-sort-improve") return 12;
    else if (sortName == "counting-sort") return 13;
    else if (sortName == "radix-sort") return 14;
    else if (sortName == "radix-sort-improve") return 15;
    else if (sortName == "flash-sort") return 16;
    else return -1;
}

int GetDataType(const std::string &dataType) {
    if (dataType == "-rand") return 0;
    else if (dataType == "-nsorted") return 1;
    else if (dataType == "-sorted") return 2;
    else if (dataType == "-rev") return 3;
    else return -1;
}

void CopyArray(int u[], int v[], int inputSize) {
    for (int i = 0; i < inputSize; ++i) {
        u[i] = v[i];
    }
}

void PrintRunTime(int a[], int inputSize, int sortFunction, bool isCompare) {
    if (!isCompare) std::cout << "Running time: ";
    else std::cout << " | ";

    auto start = std::chrono::high_resolution_clock::now();
    executeSort(a, inputSize, sortFunction);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = (end - start);
    std::cout << std::fixed << std::setprecision(6) << 1.0 * duration.count() / 1e6 << "ms";
}

void PrintComparisons(int a[], int inputSize, int sortFunction, bool isCompare) {
    if (!isCompare) std::cout << "Comparisions: ";
    else std::cout << " | ";

    long long comparisions = 0;
    executeSort(a, inputSize, sortFunction, comparisions);
    std::cout << comparisions;
}

void PrintArray(int a[], int inputSize, const std::string fileName) {
    std::ofstream outf(fileName);
    outf << inputSize << std::endl;
    for (int i = 0; i < inputSize; ++i) {
        outf << a[i] << ' ';
    }
    outf.close();
}

void GetInputData(int inputData[], int &inputSize, const std::string fileName) {
    std::ifstream inf(fileName);
    inf >> inputSize;
    for (int i = 0; i < inputSize; ++i) {
        inf >> inputData[i];
    }
    inf.close();
}

void AlgorithmMode(int argc, char **argv) {
    auto CheckOutputFlag = [&](const std::string &flag) {
        if (flag == "-both" || flag == "-time" || flag == "-comp") return true;
        return false;
    };

    auto PrintResult = [&](int a[], int inputSize, int sortFunction, const std::string &flag) {
        if (flag == "-both") {
            PrintRunTime(a, inputSize, sortFunction, 0); std::cout << std::endl;
            CopyArray(a, data, inputSize);
            PrintComparisons(a, inputSize, sortFunction, 0);
        }
        else if (flag == "-time") {
            PrintRunTime(a, inputSize, sortFunction, 0);
        }
        else if (flag == "-comp") {
            PrintComparisons(a, inputSize, sortFunction, 0);
        }
        else return false;

        return true;
    };

    if (GetSortName(std::string(argv[2])) == -1) throw ERROR;

    if (CheckOutputFlag(std::string(argv[argc - 1])) == false) throw ERROR;

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << sortName[GetSortName(std::string(argv[2]))] << std::endl;

    std::string inputParam = std::string(argv[3]);
    if (argc == 5) {
        //command 3
        if ('0' <= inputParam[0] && inputParam[0] <= '9') {
            int inputSize = std::stoi(inputParam);
            if (inputSize <= 0) throw ERROR;

            std::cout << "Input size: " << inputSize << std::endl << std::endl;
            for (int dataType = 0; dataType < 4; ++dataType) {
                std::cout << "Input order: " << dataTypeName[dataType] << std::endl;
                std::cout << "---------------------------------------------" << std::endl;
                
                GenerateData(data, inputSize, dataType);
                CopyArray(a, data, inputSize);

                std::string fileName = "input_" + std::to_string(dataType + 1) + ".txt";
                PrintArray(a, inputSize, fileName);

                PrintResult(a, inputSize, GetSortName(std::string(argv[2])), std::string(argv[4]));

                std::cout << std::endl << std::endl;
            }
        }
        else {
            //command 1
            int inputSize;

            std::string fileName(argv[3]);
            GetInputData(data, inputSize, fileName);

            std::cout << "Input file: " << fileName << std::endl;
            std::cout << "Input size: " << inputSize << std::endl;
            std::cout << "---------------------------------------------" << std::endl;

            CopyArray(a, data, inputSize);

            PrintResult(a, inputSize, GetSortName(std::string(argv[2])), std::string(argv[4]));
            PrintArray(a, inputSize, "output.txt");
        }
    }
    else if (argc == 6) {
        //command 2
        int inputSize = std::stoi(inputParam);
        if (inputSize <= 0) throw ERROR;

        std::string dataType = std::string(argv[4]);
        int dataOrder = GetDataType(dataType);
        if (dataOrder == -1) throw ERROR;

        std::cout << "Input size: " << inputSize << std::endl;
        std::cout << "Input order: " << dataTypeName[dataOrder] << std::endl;
        std::cout << "---------------------------------------------" << std::endl;

        GenerateData(data, inputSize, dataOrder);
        CopyArray(a, data, inputSize);

        PrintArray(a, inputSize, "input.txt");
        PrintResult(a, inputSize, GetSortName(std::string(argv[2])), std::string(argv[5]));
        PrintArray(a, inputSize, "output.txt");
    }
    else throw ERROR;
}

void ComparisionMode(int argc, char **argv) {
    int algo1 = GetSortName(std::string(argv[2]));
    int algo2 = GetSortName(std::string(argv[3]));
    if (algo1 == -1 || algo2 == -1) throw ERROR;

    std::cout << "COMPARISON MODE" << "\n";
    std::cout << "Algorithm: " << sortName[algo1] << " | " << sortName[algo2] << "\n";

    if (argc == 5) {
        //command 4
        std::string fileName = std::string(argv[4]);

        int inputSize;
        GetInputData(data, inputSize, fileName);

        std::cout << "Input file: " << fileName << std::endl;
        std::cout << "Input size: " << inputSize << std::endl;
        std::cout << "---------------------------------------------" << std::endl;

        CopyArray(a, data, inputSize);
        PrintRunTime(a, inputSize, algo1, 0);

        CopyArray(a, data, inputSize);
        PrintRunTime(a, inputSize, algo2, 1);

        std::cout << "\n";

        CopyArray(a, data, inputSize);
        PrintComparisons(a, inputSize, algo1, 0);

        CopyArray(a, data, inputSize);
        PrintComparisons(a, inputSize, algo2, 1);

        std::cout << "\n";
    }
    else if (argc == 6) {
        //command 5
        int inputSize = std::stoi(std::string(argv[4]));
        if (inputSize <= 0) throw ERROR;
        int inputOrder = GetDataType(std::string(argv[5]));

        std::cout << "Input size: " << inputSize << std::endl;
        std::cout << "Input order: " << dataTypeName[inputOrder] << std::endl;
        std::cout << "---------------------------------------------" << std::endl;

        GenerateData(data, inputSize, inputOrder);
        
        CopyArray(a, data, inputSize);
        PrintArray(a, inputSize, "input.txt");

        CopyArray(a, data, inputSize);
        PrintRunTime(a, inputSize, algo1, 0);

        CopyArray(a, data, inputSize);
        PrintRunTime(a, inputSize, algo2, 1);

        std::cout << "\n";

        CopyArray(a, data, inputSize);
        PrintComparisons(a, inputSize, algo1, 0);

        CopyArray(a, data, inputSize);
        PrintComparisons(a, inputSize, algo2, 1);

        std::cout << "\n";
    }
    else throw ERROR;
}
