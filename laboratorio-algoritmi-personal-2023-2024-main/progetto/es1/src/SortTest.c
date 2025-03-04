#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "unity.h"
#include "Sort.h"

/// Helper function to compare two integers.
int compare_int(const void *int1, const void *int2) {
     int a = *(int *)int1;
     int b = *(int *)int2;
  return a < b ? -1 : a == b ? 0 : 1;
}

/// Helper function to compare two doubleing point numbers.
int compare_double(const void *double1, const void *double2) {
  double a = *(double *)double1;
  double b = *(double *)double2;
  return a < b ? -1 : a == b ? 0 : 1;
}

/// Helper function to compare two strings.
int compare_str(const void *str1, const void *str2) {
    return strcmp(*(const char **)str1, *(const char **)str2);
}


/*TESTS*/

void merge_same_element_int_array()
{
  int exp_arr[] = {10, 10, 10, 10, 10};
  int shuffle_arr[] = {10, 10, 10, 10, 10};
  merge_sort(shuffle_arr, 5, sizeof(int), compare_int);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, shuffle_arr, 5);
}

void merge_int_array()
{
  int exp_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int shuffle_arr[] = {9, 4, 5, 6, 1, 3, 2, 8, 10, 7};
  merge_sort(shuffle_arr, 10, sizeof(int), compare_int);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, shuffle_arr, 10);
}

void merge_double_array()
{
  double exp_arr[] = {.0, 1.1, 1.23, 1.2567};
  double shuffle_arr[] = {1.1, .0, 1.2567, 1.23};
  merge_sort(shuffle_arr, 4, sizeof(double), compare_double);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(exp_arr, shuffle_arr, 4);
}

void merge_string_array()
{
  char *exp_arr[] = {"cacao", "cereali", "ciao", "come", "cucciolo"};
  char *shuffle_arr[] = {"ciao", "come", "cacao", "cucciolo", "cereali"};
  merge_sort(shuffle_arr, 5, sizeof(char *), compare_str);
  TEST_ASSERT_EQUAL_STRING_ARRAY(exp_arr, shuffle_arr, 5);
}

void quick_same_element_int_array()
{
  int exp_arr[] = {10, 10, 10, 10, 10};
  int shuffle_arr[] = {10, 10, 10, 10, 10};
  quick_sort(shuffle_arr, 5, sizeof(int), compare_int);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, shuffle_arr, 5);
}

void quick_int_array()
{
  int exp_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int shuffle_arr[] = {9, 4, 5, 6, 1, 3, 2, 8, 10, 7};
  quick_sort(shuffle_arr, 10, sizeof(int), compare_int);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, shuffle_arr, 10);
}

void quick_double_array()
{
  double exp_arr[] = {0, 1, 1.23, 1.2567};
  double shuffle_arr[] = {1, 0, 1.2567, 1.23};
  quick_sort(shuffle_arr, 4, sizeof(double), compare_double);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(exp_arr, shuffle_arr, 4);
}

void quick_string_array()
{
  char *exp_arr[] = {"cacao", "cereali", "ciao", "come", "cucciolo"};
  char *shuffle_arr[] = {"ciao", "come", "cacao", "cucciolo", "cereali"};
  quick_sort(shuffle_arr, 5, sizeof(char *), compare_str);
  TEST_ASSERT_EQUAL_STRING_ARRAY(exp_arr, shuffle_arr, 5);
}

int main()
{
  UNITY_BEGIN();

  //merge
  RUN_TEST(merge_same_element_int_array);
  RUN_TEST(merge_int_array);
  RUN_TEST(merge_double_array);
  RUN_TEST(merge_string_array);

  //quick 
  RUN_TEST(quick_same_element_int_array);
  RUN_TEST(quick_int_array);
  RUN_TEST(quick_double_array);
  RUN_TEST(quick_string_array);

  return UNITY_END();
}