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
#define SolutionList(T) std::vector<ISolution<T>*>

template<typename T>
void Helpers_SetSolutionsList(SolutionList(T)& solutions) {
    if (TheSolutionsInstance == 0) {
        TheSolutionsInstance = reinterpret_cast<void*>(&solutions);
    }
}

template<typename T>
void Helpers_SetSolutionsContext(T newContext) {
    SolutionList(T)& solutions = reinterpret_cast<SolutionList(T)&>(TheSolutionsInstance);

    for (var it = solutions.cbegin(); it != solutions.cend(); it++) {
        ISolution<T>* solution = *it;
        solution->SetContext(newContext);
    }
}

template<typename T>
void Helpers_RunSolutions(T ignored) {
    SolutionList(T)& solutions = reinterpret_cast<SolutionList(T)&>(TheSolutionsInstance);

    for (var it = solutions.cbegin(); it != solutions.cend(); it++) {
        ISolution<T>* solution = *it;
        solution->Run();
    }
}