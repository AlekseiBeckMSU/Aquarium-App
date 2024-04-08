#include <pch.h>
#include "gtest/gtest.h"
#include <Aquarium.h>
#include <FishBeta.h>
using namespace std;


TEST(AquariumTest, Construct){
    Aquarium aquarium;
}
TEST(AquariumTest, HitTest) {
    Aquarium aquarium;

    ASSERT_EQ(aquarium.HitTest(100, 200), nullptr) <<
                                                   L"Testing empty aquarium";

    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    aquarium.Add(fish1);
    fish1->SetLocation(100, 200);

    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish1) <<
                                                     L"Testing fish at 100, 200";
}
TEST(AquariumTest, HitTestTopImage){
    Aquarium aquarium;
    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
    aquarium.Add(fish1);
    aquarium.Add(fish2);
    fish1->SetLocation(100,200);
    fish2->SetLocation(100,200);
    ASSERT_TRUE(aquarium.HitTest(100,200) == fish2);
}
TEST(AquariumTest, HitTestEmptyAquarium){
    Aquarium aquarium;
    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    aquarium.Add(fish1);
    fish1->SetLocation(100,200);
    ASSERT_EQ(aquarium.HitTest(200,100), nullptr);
}