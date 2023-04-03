#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "cpp_free_mock.h"
#include "testfunction.c"
#include <iostream>
#include "stub.h"
#include "for_test.h"


using namespace std;
using namespace testing;

TEST(isCalibMedSpecialTonerFill, TonerFill) 
{
    EXPECT_CALL(*MOCKER(isCalibMedSpecialTonerFill), MOCK_FUNCTION())
        .Times(Exactly(1))
        .WillOnce(Return(1));
    EXPECT_EQ(1, Test_Function());
}


TEST(isCalibMedSpecialTonerFill2, TonerFill) {
    EXPECT_CALL(*MOCKER(isCalibMedSpecialTonerFill), MOCK_FUNCTION())
        .Times(Exactly(1))
        .WillOnce(Return(0));
    EXPECT_EQ(1, Test_Function());
}

TEST(ForStub, ForStub1) {
    EXPECT_CALL(*MOCKER(ForStub), MOCK_FUNCTION())
        .Times(Exactly(1))
        .WillOnce(Return(1));
    EXPECT_EQ(1, For_Test());
}

