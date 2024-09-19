#include <vector>
#include <chrono>
#include <algorithm>
#include <iostream>
#include "sorting_algorithms.h"  // Incluir los algoritmos de ordenamiento

void benchmarkSortingAlgorithms() {
    std::vector<int> sizes = {1000, 2000, 5000, 10000};  // Diferentes tamaños de entrada
    std::vector<double> bubbleSortBestTimes, bubbleSortWorstTimes, bubbleSortAverageTimes;
    std::vector<double> selectionSortBestTimes, selectionSortWorstTimes, selectionSortAverageTimes;
    std::vector<double> mergeSortBestTimes, mergeSortWorstTimes, mergeSortAverageTimes;

    for (int N : sizes) {
        // Mejor caso: lista ya ordenada
        std::vector<int> bestCase(N);
        std::iota(bestCase.begin(), bestCase.end(), 0);  // Lista ordenada

        // Peor caso: lista en orden inverso
        std::vector<int> worstCase(bestCase.rbegin(), bestCase.rend());

        // Caso promedio: datos aleatorios
        std::vector<int> averageCase(N);
        std::generate(averageCase.begin(), averageCase.end(), rand);

        // --- BubbleSort ---
        // Mejor caso
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(bestCase);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        bubbleSortBestTimes.push_back(duration.count());

        // Peor caso
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(worstCase);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        bubbleSortWorstTimes.push_back(duration.count());

        // Caso promedio
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(averageCase);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        bubbleSortAverageTimes.push_back(duration.count());

        // --- SelectionSort ---
        // Mejor caso
        start = std::chrono::high_resolution_clock::now();
        selectionSort(bestCase);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        selectionSortBestTimes.push_back(duration.count());

        // Peor caso
        start = std::chrono::high_resolution_clock::now();
        selectionSort(worstCase);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        selectionSortWorstTimes.push_back(duration.count());

        // Caso promedio
        start = std::chrono::high_resolution_clock::now();
        selectionSort(averageCase);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        selectionSortAverageTimes.push_back(duration.count());

        // --- MergeSort ---
        // Mejor caso
        start = std::chrono::high_resolution_clock::now();
        mergeSort(bestCase, 0, bestCase.size() - 1);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        mergeSortBestTimes.push_back(duration.count());

        // Peor caso
        start = std::chrono::high_resolution_clock::now();
        mergeSort(worstCase, 0, worstCase.size() - 1);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        mergeSortWorstTimes.push_back(duration.count());

        // Caso promedio
        start = std::chrono::high_resolution_clock::now();
        mergeSort(averageCase, 0, averageCase.size() - 1);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        mergeSortAverageTimes.push_back(duration.count());
    }

    // Graficar resultados de BubbleSort
    plotBenchmarkResults(bubbleSortBestTimes, bubbleSortWorstTimes, bubbleSortAverageTimes, sizes);

    // Graficar resultados de SelectionSort
    plotBenchmarkResults(selectionSortBestTimes, selectionSortWorstTimes, selectionSortAverageTimes, sizes);

    // Graficar resultados de MergeSort
    plotBenchmarkResults(mergeSortBestTimes, mergeSortWorstTimes, mergeSortAverageTimes, sizes);

    std::cout << "Benchmark completado para BubbleSort, SelectionSort y MergeSort" << std::endl;
}
