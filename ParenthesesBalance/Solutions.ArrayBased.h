class Solution_ArrayBased : public ISolution<BoolReturn, Context> {
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

        // Everything else        
        var tracker = 0;
        for (var character : _context.Parantheses) {
            if (character == '(') {
                ++tracker;
            }
            else if (character == ')') {
                --tracker;
            }
        }

        returnValue.IsTrue = (tracker == 0);

        return returnValue;
    }
};