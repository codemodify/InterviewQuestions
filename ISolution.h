#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

#define var auto

struct BoolReturn {
    bool IsTrue;
    std::string Message;
    
    BoolReturn() {
        IsTrue = false;
        Message = "";
    }
};

// NEVER, EVER do macros. I do them because I'm cool
#define IMPLEMENT_RTTI \
    std::string About() { \
        std::string nameWithNoise = typeid(this).name(); \
        return nameWithNoise.substr(3); \
    }

template<typename OutputType, typename InputType>
class ISolution {
    public:
        void SetContext(InputType newContext) {
            _context = newContext;
        }

        virtual std::string About() = 0; //{
        //      return typeid(this).name();
        // }

        virtual OutputType Run() = 0;
        
    protected:
        InputType _context;
};

template<typename OutputType, typename InputType>
class SolutionRunner {
    std::vector<ISolution<OutputType, InputType>*> _solutions;

    public:
        void Add(ISolution<OutputType, InputType>* solution) {
            _solutions.push_back(solution);
        }

        void Run(InputType context, std::function<void(OutputType, ISolution<OutputType, InputType>&)> finishDelegate) {
            for (var solution : _solutions) {
                solution->SetContext(context);
                
                OutputType result = solution->Run();
                finishDelegate(result, *solution);
            }
        }
};