class Solution_StackBased : public ISolution<Context> {
    void Run() {
        std::cout 
            << "Solution_StackBased"
            << _context.Parantheses
            << std::endl;
    }
};