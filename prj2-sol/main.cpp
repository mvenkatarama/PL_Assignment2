#include "errors.h"
#include "OneDArray.h"

#include <iostream>
#include <memory>

#include <cassert>

using namespace std;

typedef struct {
  size_t nOps;
  size_t nEntriesA, nEntriesB, nEntriesRes;
} Params;

typedef double Entry;


static void loopVectorSum(size_t nOps,
                            size_t nEntriesA,
                            OneDArray& arr1,
                            OneDArray& arr2,
                            OneDArray& result,
                            std::istream &in, std::ostream &out);
static Params getParams(int argc, char *argv[]);
void addVectors(OneDArray& arr1, OneDArray& arr2, OneDArray& result, size_t nEntries);



void addVectors(OneDArray& arr1, OneDArray& arr2, OneDArray& result, size_t nEntries){
        for (size_t j = 0; j < nEntries; j++) {
            result.entries[j] = arr1.entries[j] + arr2.entries[j];
            // std::cout << "debug" << result.entries[j] << " "<< arr1.entries[j] << " " << arr2.entries[j]<<"\n";
        }
}

static void loopVectorSum(size_t nOps,
                            size_t nEntriesA,
                            OneDArray& arr1,
                            OneDArray& arr2,
                            OneDArray& result,
                            std::istream &in, std::ostream &out)
{
    for (size_t i = 0; i < nOps; i++)  {
        for (size_t j = 0; j < nEntriesA; j++) {
            Entry entry;
            std::cin >> entry;
            arr1.entries[j] = entry;
            // Entry entry;
            // if (in >> entry) { 
            //     arr1.entries[j] = entry;
            // }
        }

        for (size_t j = 0; j < nEntriesA; j++) {
            Entry entry;
            std::cin >> entry;
            arr2.entries[j] = entry;
            // Entry entry;
            // if (in >> entry) { //read succeeded
            //     arr2.entries[j] = entry;
            // }
        }

        addVectors(arr1, arr2, result, nEntriesA);

        for (size_t j = 0; j < nEntriesA; j++) {
                std::cout << result.entries[j] << " ";
            }
        std::cout << "\n\n";
        }

  }


int main(int argc, char* argv[]) {   
    Params params = getParams(argc, argv);

    try {
        OneDArray arr1(params.nEntriesA);
        OneDArray arr2(params.nEntriesB);
        OneDArray result(params.nEntriesRes);

        loopVectorSum(params.nOps, params.nEntriesA, arr1, arr2, result, std::cin, std::cout);
    }
    catch (const std::bad_alloc &err) {
        std::cerr << "memalloc failure" << std::endl;
    }

    return 0;

}

const char *PARAM_NAMES[] = { "N_OPS", "N_ENTRIES" };
#define N_PARAMS (sizeof(PARAM_NAMES)/sizeof(PARAM_NAMES[0]))


static Params getParams(int argc, char *argv[]) {
  if (argc != N_PARAMS + 1) {
    panic("Usage: %s %s %s \n", argv[0], PARAM_NAMES[0], PARAM_NAMES[1]);
    // std::cout << "Usage: ./<program_name> <N_OPS> <N_ENTRIES>\n";
  }
  size_t paramVals[N_PARAMS];
  for (size_t i = 0; i < N_PARAMS; i++) {
    char *p; //will be pointed to first non-digit by strtol()
    long val = strtol(argv[i + 1], &p, 10);
    assert(sizeof(size_t) >= sizeof(long));
    paramVals[i] = val;
  }
  Params params = {
    .nOps=paramVals[0],
    .nEntriesA = paramVals[1],
    .nEntriesB = paramVals[1],
    .nEntriesRes = paramVals[1]
  };
  return params;
}


    /*
    if(argc != 3) {
        // std::cout << "argc : "+to_string(argc)+"\n";
        std::cout << "Usage: ./<program_name> <N_OPS> <N_ENTRIES>\n";
        return 1;
    }

    int N_OPS = atoi(argv[1]);
    int N_ENTRIES = atoi(argv[2]);

    // std::cout << N_OPS << "\n";
    // std::cout << N_ENTRIES << "\n";

    // int arr1[N_ENTRIES], arr2[N_ENTRIES], result[N_ENTRIES];

    std::unique_ptr<int[]> arr1 = std::make_unique<int[]>(N_ENTRIES);
    std::unique_ptr<int[]> arr2 = std::make_unique<int[]>(N_ENTRIES);
    std::unique_ptr<int[]> result = std::make_unique<int[]>(N_ENTRIES);


    for(int i=0; i<N_OPS; i++) {
        for(int j=0; j<N_ENTRIES; j++) {
            std::cin >> arr1[j];
        }
        for(int j=0; j<N_ENTRIES; j++) {
            std::cin >> arr2[j];
        }
        for(int j=0; j<N_ENTRIES; j++) {
            result[j] = arr1[j] + arr2[j];
        }
        for(int j=0; j<N_ENTRIES; j++) {
            std::cout << result[j] << " ";
        }
        std::cout <<"\n\n";
    }

    // std::cout << "\n";
    return 0;
    */
// }