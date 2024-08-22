
#ifndef AWARDS_H
#define AWARDS_H

#include <string>


namespace awards {


class RankList {
public:
  virtual std::string getNext() = 0;
};


class AwardCeremonyActions {
public:
  virtual void playAnthem() = 0;
  virtual void turnOffTheLightsAndGoHome() = 0;
  virtual void awardBronze(std::string recipient) = 0;
  virtual void awardSilver(std::string recipient) = 0;
  virtual void awardGold(std::string recipient) = 0;
};


void performAwardCeremony(RankList& recipients, AwardCeremonyActions& actions);


}


#endif

