
#include "../ISolution.h"

#include "Context.h"
#include "Solutions.ArrayBased.h"
#include "Solutions.StackBased.h"

void SolutionFinished(BoolReturn result, ISolution<BoolReturn, Context>& solutionInstance) {
    std::cout
        << "\t" << solutionInstance.About()
        << "\t" << (result.IsTrue ? " true" : " false")
        << "\t" << result.Message
        << std::endl;
}

int main() {
    std::vector<std::string> parantheses;
    parantheses.push_back("((()))()");
    parantheses.push_back(")(()))((");
    parantheses.push_back("()()))))");
    parantheses.push_back("((()))()");
    parantheses.push_back("()(()");

    SolutionRunner<BoolReturn, Context> solutions;
    solutions.Add(new Solution_ArrayBased());
    solutions.Add(new Solution_StackBased());

    for (var item : parantheses) {
        Context context;
        context.Parantheses = item;

        std::cout << "Running: " << context.GetContextAsStringToDisplay() << std::endl;
        solutions.Run(context, SolutionFinished);
    }
}
