#ifndef GENERAL_H
#define GENERAL_H

struct suggested_Move {
    Region* from;
    Region* to;
    float percentageMove; //a float who's value is from 0 to 1, representing the percent of available troops to move, always leaving 1.
}SuggestedMove;

class General {
    
    public:
        
        General();
        
        virtual ~General();
        
        /** calculateStrategy
         *  
         *  This function prioritizes different troop placements and
         *  prioritizes different attacks and moves taking into account the
         *  results from getAttack and getDefense.
         */
        void calculateStrategy();
        
        /** placeReinforcements
         *  
         *  This function places troops during the add reinforcements phase
         *  
         */
        void placeReinforcements(); //may need additional parameters later
        
        /** makeMoves
         *  
         *  This function makes the attacks and transfers during the attack/transfer
         *  phase.
         *  
         */
        void makeMoves();

    protected:
        

    private:
        
        //will also need a data structure for storing suggested moves
        
        Map* gameMap;
        
};

#endif // GENERAL_H
