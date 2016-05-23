class Solution_StackBased : public ISolution<BoolReturn, Context> {
    IMPLEMENT_RTTI
    
    BoolReturn Run() {
        BoolReturn returnValue;
        
        // Corner cases
        if (
               _context.Parantheses.length() == 0
            || _context.Parantheses[0] == ')'
            || _context.Parantheses[_context.Parantheses.length()] == '('
        ) {
            return returnValue;
        }        
        
        std::stack<int> theStack;
        for (var character : _context.Parantheses) {
            if (character == '(') {
                theStack.push(1);
            }
            else {
                theStack.pop();
            }
        }
        
        returnValue.IsTrue = (theStack.size() == 0);

        return returnValue;
    }
};