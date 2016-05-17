
#include "../ISolution.h"

#include "Context.h"
#include "Solutions.ArrayBased.h"
#include "Solutions.StackBased.h"

// typedef void (*SolutionDelegate)(std::string& parantheses);
// void Solution_ArrayBased(std::string& parantheses);
// void Solution_StackBased(std::string& parantheses);

int main() {
    std::vector<std::string> parantheses;
    parantheses.push_back("((()))()");

    SolutionList(Context) solutions;
    solutions.push_back(new Solution_ArrayBased());
    solutions.push_back(new Solution_StackBased());

    Helpers_SetSolutionsList(solutions);

    for (var it1 = parantheses.cbegin(); it1 != parantheses.cend(); it1++) {
        Context context;
        context.Parantheses = *it1;

        Helpers_SetSolutionsContext(context);
        Helpers_RunSolutions(context);
    }
}
