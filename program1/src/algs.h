#ifndef ALGS_H
#define ALGS_H

#include <string>
#include <algorithm>
#include <queue>
#include <array>
using std::swap;



template<typename T>
void heapsort(std::vector<T>& V){
	std::priority_queue<T> heap;

	for (const T& i : V) {
        heap.push(i);
    }

	for (int i = V.size() - 1; i >= 0; i--) {
        V[i] = heap.top(); 
		heap.pop();
    }
}



bool are_anagrams(std::string a, std::string b) {
    if (a.size() != b.size()) {
        return false;
    }

    const int k = 26; 

    std::array<int, k> charCount = {0};

    for (char c : a) {
        charCount[c - 'A']++;
    }

    for (char c : b) {
        if (--charCount[c - 'A'] < 0) {
            return false;  
        }
    }

    return true;
}


#endif
