#include <iostream>
#include <vector>
#include <string>
#include <map>

#define var auto

template<typename T> 
class ISolution {
    public:
        void SetContext(T newContext) {
            _context = newContext;
        }

        virtual void Run() = 0;
        
    protected:
        T _context;
};

static void* TheSolutionsInstance = 0;
#define SolutionList std::vector<ISolution<T>*>

template<typename T>
void Helpers_SetSolutionsList(SolutionList& solutions) {
    if (TheSolutionsInstance == 0) {
        TheSolutionsInstance = solutions;
    }
}

template<typename T>
void Helpers_SetSolutionsContext(T newContext) {
    SolutionList& solutions = reinterpret_cast<SolutionList>(TheSolutionsInstance);

    for (var it = solutions.cbegin(); it != solutions.cend(); it++) {
        ISolution<T>* solution = *it;
        solution->SetContext(newContext);
    }
}

template<typename T>
void Helpers_RunSolutions(T ignored) {
    SolutionList& solutions = reinterpret_cast<SolutionList>(TheSolutionsInstance);

    for (var it = solutions.cbegin(); it != solutions.cend(); it++) {
        ISolution<T>* solution = *it;
        solution->Run();
    }
}