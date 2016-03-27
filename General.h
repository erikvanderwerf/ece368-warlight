#ifndef GENERAL_H
#define GENERAL_H

#include <vector>

#include "Bot.h"
#include "region.h"
#include "SuperRegion.h"

typedef struct SUGGESTED_MOVE {
    Region* from;
    Region* to;
    float percentageMove; //a float who's value is from 0 to 1, representing the percent of available troops to move, always leaving 1.
} SUGGESTED_MOVE;

class General {
    
    public:
        
        General(Bot* bot);
        
        virtual ~General();
        
        
        /** \brief Calculates the suggested attacks for this turn.
         *
         *
         */                          
        std::vector<SUGGESTED_MOVE> getAttack();
        
        /** \brief Calculates the suggested defensive moves for this turn.
         * a suggested move can be to keep troops in a region.
         *
         */  
        std::vector<SUGGESTED_MOVE> getDefense();
        
        /** calculateStrategy
         *  
         *  This function prioritizes different troop placements and
         *  prioritizes different attacks and moves taking into account the
         *  results from getAttack and getDefense.
         */
        std::vector<SUGGESTED_MOVE> calculateStrategy(); //will clear suggested attacks and suggested defences
        
        /** \brief This function places the number of reinforcements according the weights calculated by the general.
         *
         * \param numReinforcements int the number of reinforcements available to add
         * \return void
         */                                            
        std::vector<SUGGESTED_MOVE> placeReinforcements(int numReinforcements); //may need additional parameters later
        
        /** makeMoves
         *  
         *  This function makes the attacks and transfers during the attack/transfer
         *  phase.
         *  
         */
        void makeMoves(); //calling this function will clear m_suggestedMoves

    private:
        
        std::vector<SUGGESTED_MOVE> m_suggestedAttacks;
        
        //suggested moves with to and from as the same region
        std::vector<SUGGESTED_MOVE> m_suggestedDefenses;
        
        //suggested moves with from region as null
        std::vector<SUGGESTED_MOVE> m_suggestedReinforcements;
        
        std::vector<SUGGESTED_MOVE> m_plannedMoves;
        
        Map gameMap;
        
};

#endif // GENERAL_H
