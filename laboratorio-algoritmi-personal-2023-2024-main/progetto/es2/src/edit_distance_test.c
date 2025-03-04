#include "unity.h"
#include "edit_distance.h" 

/// Test for the recursive version
void test_edit_distance() {
    TEST_ASSERT_EQUAL(1, edit_distance("casa", "cassa"));
    TEST_ASSERT_EQUAL(2, edit_distance("casa", "cara"));
    TEST_ASSERT_EQUAL(2, edit_distance("vinaio", "vino"));
    TEST_ASSERT_EQUAL(4, edit_distance("tassa", "passato"));
    TEST_ASSERT_EQUAL(0, edit_distance("pioppo", "pioppo"));
}

void test_edit_distance_dy(){
    TEST_ASSERT_EQUAL(1, edit_distance_dy("casa", "cassa",  memo_table(4, 5)));
    TEST_ASSERT_EQUAL(2, edit_distance_dy("casa", "cara",  memo_table(4, 4)));
    TEST_ASSERT_EQUAL(2, edit_distance_dy("vinaio", "vino",  memo_table(6, 4)));
    TEST_ASSERT_EQUAL(4, edit_distance_dy("tassa", "passato",  memo_table(5, 7)));
    TEST_ASSERT_EQUAL(0, edit_distance_dy("pioppo", "pioppo",  memo_table(6, 6)));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_edit_distance);
    RUN_TEST(test_edit_distance_dy);
    return UNITY_END();
}