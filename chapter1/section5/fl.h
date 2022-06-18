#include <math.h>

static inline double
fl(double value, unsigned int precision) {
  int    exp10    = ceil(log10(value));
  double sig10    = value / pow(10, exp10);
  double to_round = nextafter(sig10 * pow(10, precision), INFINITY);
  double rounded  = round(to_round);
  double fl       = pow(10, exp10) * rounded / pow(10, precision);
  return fl;
}
