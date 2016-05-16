#include <iostream>
#include <map>

#define k_T 10
#define k_SIZE 5
#define k_SIZE_PlusTwo (k_SIZE+2)

void O_N2_Time(int a[]);
void O_N__Time(int a[]);

void Helpers_PrintArray(int a[], int length);
void Helpers_PrintMap(std::map<int, int> theMap);

int main() {
    int a[] = {4, 6, 3, 7, -10};

    //O_N2_Time(a);
    O_N__Time(a);
}

void O_N2_Time(int a[]) {
    int count = 0;
    for (int i=0; i < k_SIZE; i++) {
        int sum = a[i];
        for (int j=i+1; j < k_SIZE; j++) {
            sum+=a[j];
            if (sum == k_T) {
                count++;
            }
        }
    }

    std::cout << count;
}

void O_N__Time(int a[]) {
    int A[] = {0, 0, 0, 0, 0, 0, 0};

    for (int i=0, j=1; i < k_SIZE; i++, j++) {
        A[j] = a[i] + A[j-1]; // This should become from {4, 6, 3, 7, -10} to {0, 4, 10, 13, 20, 10, 0}
    }

    Helpers_PrintArray(A, k_SIZE_PlusTwo);

    std::map<int, int> hits;
    hits.insert(std::pair<int,int>(0,0));

    for (int i=0; i<k_SIZE_PlusTwo; i++) {
        if (hits.find(A[i]) == hits.end()) {
            if ((A[i] % k_T) == 0 ) {
                hits.insert(std::pair<int,int>(A[i], A[i] / k_T));
            }
        }
    }
    Helpers_PrintMap(hits);

    int count = 0;
    for (std::map<int,int>::iterator it=hits.begin(); it!=hits.end(); ++it) {
        count += it->second;
    }

    std::cout << count;
}

// Helpers
// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~
void Helpers_PrintArray(int a[], int length) {
    for (int i=0; i < length; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
void Helpers_PrintMap(std::map<int, int> theMap) {
    for (std::map<int,int>::iterator it=theMap.begin(); it!=theMap.end(); ++it) {
        std::cout
            << it->first
            << " => "
            << it->second
            << std::endl;
    }
}