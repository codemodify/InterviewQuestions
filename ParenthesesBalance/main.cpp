
#include "../ISolution.h"

#include "Context.h"
#include "Solutions.ArrayBased.h"
#include "Solutions.StackBased.h"

int main() {
    std::vector<std::string> parantheses;
    parantheses.push_back("((()))()");

    SolutionRunner<Context> solutions;
    solutions.Add(new Solution_ArrayBased());
    solutions.Add(new Solution_StackBased());

    for (var it1 = parantheses.cbegin(); it1 != parantheses.cend(); it1++) {
        const std::string& data = *it1;
        
        Context context;
        context.Parantheses = data;

        solutions.Run(context);
    }
}
