#ifndef BUILDER_NGRAM__
#define BUILDER_NGRAM__

#include "lm/word_index.hh"

#include <inttypes.h>
#include <string.h>

namespace lm {
namespace builder {

template <unsigned N> struct NGram {
  static const unsigned n = N;
  WordIndex w[N];
  bool operator==(const NGram<N> &gram) const {
    return !memcmp(w, gram.w, sizeof(w));
  }
};

template <unsigned N> struct CountedNGram : NGram<N> {
  uint64_t count;
};

template <unsigned N> struct UninterpNGram : NGram<N> {
  float prob;  // Uninterpolated probability.
  float gamma; // Interpolation weight for lower order.
};

const WordIndex kBOS = 1;

#define STATICALLY_DISPATCH(i) do { \
  switch (i) { \
    case 1: do { XX(1); } while(0); break; \
    case 2: do { XX(2); } while(0); break; \
    case 3: do { XX(3); } while(0); break; \
    case 4: do { XX(4); } while(0); break; \
    case 5: do { XX(5); } while(0); break; \
    default: \
      fprintf(stderr, "%d-grams are not supported; please, accomodate ngram.hh to your needs\n", i); \
      break; \
  } \
} while(0)

} // namespace builder
} // namespace lm

#endif // BUILDER_NGRAM__