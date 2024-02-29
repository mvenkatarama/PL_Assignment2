#include <iostream>
#include <memory>

class OneDArray {
    public:
        const size_t nEntries;
        typedef double Entry;
        std::unique_ptr<Entry[]> entries;

      OneDArray(size_t nEntries);

      ~OneDArray() {
    // std::cerr << "free Matrix[" << nEntries << "]" << std::endl;
      }
};
