
#include "../include/Awards.h"


using awards::RankList;
using awards::AwardCeremonyActions;


void
awards::performAwardCeremony(RankList& recipients, AwardCeremonyActions& actions) {
  actions.playAnthem();
  actions.awardBronze(recipients.getNext());
  actions.awardSilver(recipients.getNext());
  actions.awardGold(recipients.getNext());
  actions.turnOffTheLightsAndGoHome();
}


