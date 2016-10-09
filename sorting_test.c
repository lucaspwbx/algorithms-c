#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<cmocka.h>
#include<stdlib.h>
#include<stdio.h>

void selection_sort(int *array, int length) {
  int i, j, temp;
  for (i = 0; i < length; i++) {
    for (j = i + 1; j < length; j++) {
      if (array[i] > array[j]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

static void selection_sort_test(void **state) {
  (void) state;

  int i;
  int expected[] = {1, 3, 7, 9};
  int array[] = {9, 3, 7, 1};
  selection_sort(array, 4);
  for (i = 0; i < 4; i++) {
    assert_int_equal(array[i], expected[i]);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(selection_sort_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
