#include "OneDArray.h"

OneDArray::OneDArray(size_t nEntries) : nEntries(nEntries),
entries(std::make_unique<Entry[]>(nEntries)) {
      // std::cerr << "alloc 1D vector[" << nEntries << "]" << std::endl;
}
