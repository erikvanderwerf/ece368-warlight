#ifndef GENERAL_H
#define GENERAL_H

#include <vector>

#include "Bot.h"
#include "region.h"
#include "SuperRegion.h"

typedef struct suggested_Move {
    Region* from;
    Region* to;
    float percentageMove; //a float who's value is from 0 to 1, representing the percent of available troops to move, always leaving 1.
}SuggestedMove;

class General {
    
    public:
        
        General(Bot* bot);
        
        virtual ~General();
        
        
        /** \brief Calculates the suggested attacks for this turn.
         *
         *
         */                          
        void getAttack();
        
        /** \brief Calculates the suggested defensive moves for this turn.
         * a suggested move can be to keep troops in a region.
         *
         */                          
        void getDefense();
        
        /** calculateStrategy
         *  
         *  This function prioritizes different troop placements and
         *  prioritizes different attacks and moves taking into account the
         *  results from getAttack and getDefense.
         */
        void calculateStrategy(); //will clear suggested attacks and suggested defences
        
        /** \brief This function places the number of reinforcements according the weights calculated by the general.
         *
         * \param numReinforcements int the number of reinforcements available to add
         * \return void
         */                                            
        void placeReinforcements(int numReinforcements); //may need additional parameters later
        
        /** makeMoves
         *  
         *  This function makes the attacks and transfers during the attack/transfer
         *  phase.
         *  
         */
        void makeMoves(); //calling this function will clear m_suggestedMoves

    protected:
        

    private:
        
        std::vector<SuggestedMove*> m_suggestedAttacks;
        
        std::vector<SuggestedMove*> m_suggestedDefenses; //suggested moves with to and from as the same region
        
        std::vector<SuggestedMove*> m_suggestedReinforcements; //suggested moves with from region as null
        
        std::vector<SuggestedMove*> m_plannedMoves;
        
        Map* gameMap;
        
        Bot* m_bot;
        
};

#endif // GENERAL_H
