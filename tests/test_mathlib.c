//
// Created by zeze on 23/08/24.
//
#include "unity.h"
#include "mathlib.h"

void setUp(void) {
    // Configurações iniciais (executado antes de cada teste)
}

void tearDown(void) {
    // Limpeza após cada teste
}


void test_add(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3));
    TEST_ASSERT_EQUAL(-1, add(-2, 1));
    TEST_ASSERT_EQUAL(0, add(0, 0));
}

void test_subtract(void) {
    TEST_ASSERT_EQUAL(1, subtract(3, 2));
    TEST_ASSERT_EQUAL(-3, subtract(-2, 1));
    TEST_ASSERT_EQUAL(0, subtract(0, 0));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add);
    RUN_TEST(test_subtract);
    return UNITY_END();
}