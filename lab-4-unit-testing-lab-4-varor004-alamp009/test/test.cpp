#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Awards.h"
#include "../include/Hailstone.h"
#include "../include/Triangle.h"

#include <vector> 
#include <string>

using sequence::satisfiesHailstone;
using shapes::Triangle;

//create a stub for RankList.
//To create a stub for RankList, create a dervied class 
//from RankList and implement a simple simulation of the 
//getNext() method using a hardcoded list of names.

class StubList : public awards::RankList {
private: 
    std::vector<std::string> names; 
    unsigned currIndex; 
public:
    StubList(): currIndex(-1) {
        // Initialize the hardcoded list of names
        names = {"Alice", "Bob", "Charlie", "David", "Ethan"};
    }
    std::string getNext(){
        if ( currIndex < names.size() - 1 )
            return names.at(currIndex++); 
        else
            return ""; 
    }
};

//Create a mock for AwardCeremonyActions. It should be able to simulate 
//the call to the following methods: playAnthem(), awardBronze(),
//awardSilver(), awardGold(), and turnOffTheLightsAndGoHome().

class MockAwards : public awards::AwardCeremonyActions
{
    public:
        MOCK_METHOD(void, playAnthem, (), (override));
        MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
        MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
        MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
        MOCK_METHOD(void, awardGold, (std::string recipient), (override));
};

TEST(AwardsTests, ceremonyCalls) { //passes
    MockAwards mock;
    StubList people;  
    {
        testing::InSequence seq; 
        EXPECT_CALL(mock, playAnthem());
        EXPECT_CALL(mock, awardBronze(people.getNext()));
        EXPECT_CALL(mock, awardSilver(people.getNext()));
        EXPECT_CALL(mock, awardGold(people.getNext()));
        EXPECT_CALL(mock, turnOffTheLightsAndGoHome());
    }
    performAwardCeremony(people, mock); 
}

TEST(AwardsTests, ceremonyCallsWrong) { //fails 
    MockAwards mock;
    StubList people;  
    {
        testing::InSequence seq; 
        EXPECT_CALL(mock, turnOffTheLightsAndGoHome()); //shouldn't be first
        EXPECT_CALL(mock, playAnthem());
        EXPECT_CALL(mock, awardBronze(people.getNext()));
        EXPECT_CALL(mock, awardSilver(people.getNext()));
        EXPECT_CALL(mock, awardGold(people.getNext()));
    }
    performAwardCeremony(people, mock);
}

TEST (TestHailstone, testInputZero){
    bool value = satisfiesHailstone(0);
    EXPECT_FALSE(value);
}

TEST (TestHailstone, testInputOne){
    bool value1 = satisfiesHailstone(1);
    EXPECT_TRUE(value1);
}

TEST (TestHailstone, testInputEven){
    bool value2 = satisfiesHailstone(2);
    EXPECT_TRUE(value2);
}

TEST (TestHailstone, testInputOdd){
    bool value3 = satisfiesHailstone(5);
    EXPECT_TRUE(value3);
}

TEST (TestHailstone, testInputNegative){
    bool value4 = satisfiesHailstone(-2);
    EXPECT_TRUE(value4);
}

TEST(TriangleTests, testPerimeter) { //passes despite bugs
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

TEST(TriangleTests, testAreaEqui) { //passes despite bugs 
    Triangle *aTriangle = new Triangle(1,1,1); 

    EXPECT_LT(aTriangle->getArea(), .44); 
    EXPECT_GT(aTriangle->getArea(), .42);
}

TEST(TriangleTests, testKindIso) { //passes despite bugs 
    Triangle *aTriangle = new Triangle(2,2,1); 

    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::ISOSCELES); 
}

TEST(TriangleTests, testAreaRuns) { //passes despite bugs 
    Triangle *aTriangle = new Triangle(7,5,6); 

    EXPECT_NO_THROW(aTriangle->getArea()); 
}

TEST(TriangleTests, firstShortest) { //passes 
    EXPECT_DEATH({
        Triangle *aTriangle = new Triangle(1,5,5);
    }, "First side is not the longest");
}
TEST(TriangleTests, notEquality) { //passes 
    EXPECT_DEATH({
        Triangle *aTriangle = new Triangle(10,1,1);
    }, "Does not satisfy triangle inequality");
}



TEST(TriangleTests, testPerimeterDiffSides) { //doesn't pass bc of bugs
    Triangle *aTriangle = new Triangle(2,2,1);
    EXPECT_EQ (aTriangle->getPerimeter(),5);
}

TEST(TriangleTests, testAreaDiffSides) { //doesn't pass bc of "bugs" 
    Triangle *aTriangle = new Triangle(2,2,1); 

    EXPECT_LT(aTriangle->getArea(), .97); 
    EXPECT_GT(aTriangle->getArea(), .95);
}

TEST(TriangleTests, testKindEqui) { //doesn't pass bc of bugs 
    Triangle *aTriangle = new Triangle(1,1,1); 

    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::EQUILATERAL); 

}