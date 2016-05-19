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

template<typename T>
class SolutionRunner {
    std::vector<ISolution<T>*> _solutions;

    public:
        void Add(ISolution<T>* solution) {
            _solutions.push_back(solution);
        }

        void Run(T context) {
            for (var it = _solutions.cbegin(); it != _solutions.cend(); it++) {
                ISolution<T>* solution = *it;
                solution->SetContext(context);
                solution->Run();
            }
        }
};