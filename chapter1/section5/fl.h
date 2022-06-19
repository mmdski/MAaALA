#include <math.h>

static inline double
fl(double value, unsigned int precision) {

  int    exp10;
  double inf;

  if (value > 0) {
    exp10 = (int) ceil(log10(value));
    inf   = INFINITY;
  } else if (value < 0) {
    exp10 = (int) ceil(log10(-value));
    inf   = -INFINITY;
  } else {
    return value;
  }

  double sig10    = value / pow(10, exp10);
  double to_round = nextafter(sig10 * pow(10, precision), inf);
  double rounded  = round(to_round);
  double fl       = pow(10, exp10) * rounded / pow(10, precision);
  return fl;
}
