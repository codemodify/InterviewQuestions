
#include "../ISolution.h"

#include "Context.h"
#include "Solutions.ArrayBased.h"
#include "Solutions.StackBased.h"

void SolutionFinished(BoolReturn result, void* solutionInstance) {
    std::cout
        << "Finished: " << typeid(solutionInstance).name()
        << result.IsTrue
        << result.Message
        << std::endl;
}

int main() {
    std::vector<std::string> parantheses;
    parantheses.push_back("((()))()");

    SolutionRunner<BoolReturn, Context> solutions;
    solutions.Add(new Solution_ArrayBased());
    solutions.Add(new Solution_StackBased());

    for (var item : parantheses) {
    // for (var it1 = parantheses.cbegin(); it1 != parantheses.cend(); it1++) {
    //     const std::string& data = *it1;
        
        Context context;
        context.Parantheses = item;

        solutions.Run(context, SolutionFinished);
    }
}
