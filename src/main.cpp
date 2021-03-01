#include "arrays.h"
#include "functions.h"
#include "heap.h"
#include "namespace.h"
#include "references.h"
#include "strings.h"
#include "variables.h"

int main() {
  namespace_run();
  // functions_run();
  strings_run();
  variables_run();
  arrays_run();
  heap_run();
  references_run();
  return 0;
}