#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "A.h"

class MockA {
public:
    MOCK_METHOD0(getInstance, A*());
    MOCK_METHOD0(AConstructor, void());
    void ADestructor() {
        std::cout << "ADestructor called" << std::endl;
    }
    MOCK_METHOD0(ADestructor, void());
};

MockA* mockA = nullptr;

A* A::getInstance() {
    static A instance;  
    return &instance;
}

A::A() {
      std::cout << "construct " << std::endl;
      mockA->AConstructor();
}

~A() {
        std::cout << "Destructing A" << std::endl;
        if (mockA != nullptr) {
            mockA->ADestructor();
        }

TEST(ATest, GetInstanceCalledOnce) {
    MockA mock;
    mockA = &mock;

    EXPECT_CALL(mock, AConstructor()).Times(1);
    EXPECT_CALL(mock, ADestructor()).Times(1);
    
    A* pa1 = A::getInstance();
    A* pa2 = A::getInstance();

    mockA = nullptr;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

