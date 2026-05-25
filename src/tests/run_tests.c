#include <stdio.h>
#include <stdlib.h>

#include "check_basic_suites.h"

int main(void) {
  SRunner* sr = srunner_create(NULL);

  // Безопасное добавление suite'ов с проверкой
  Suite* suites[] = {memchr_suite(),   memcmp_suite(),   memcpy_suite(),
                     memset_suite(),   strncat_suite(),  strchr_suite(),
                     strncmp_suite(),  strncpy_suite(),  strcspn_suite(),
                     strerror_suite(), strlen_suite(),   strpbrk_suite(),
                     strrchr_suite(),  strstr_suite(),   strtok_suite(),
                     to_upper_suite(), to_lower_suite(), insert_suite(),
                     trim_suite(),     sscanf_suite(),   sprintf_suite()};

  int num_suites = sizeof(suites) / sizeof(suites[0]);

  for (int i = 0; i < num_suites; i++) {
    if (suites[i] != NULL) {
      srunner_add_suite(sr, suites[i]);
    }
  }

  srunner_run_all(sr, CK_NORMAL);  // Используем CK_NORMAL вместо CK_ENV

  int number_failed = srunner_ntests_failed(sr);

  printf("\nSUMMARY:\n");
  printf("  Total Tests:  %d\n", srunner_ntests_run(sr));
  printf("  Passed:       %d\n", srunner_ntests_run(sr) - number_failed);
  printf("  Failed:       %d\n", number_failed);

  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}