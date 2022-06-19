#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "fl.h"

void
print_frexp(double value) {
  int    exp;
  double x = frexp(value, &exp);
  printf("value = %g, x = %.20e, exp = %d\n", value, x, exp);
}

void
print_fl_steps(double a, double b, unsigned int precision) {

  double value = a / b;

  printf("a / b = %g / %g\n", a, b);
  printf("value = %g\n", value);

  int    exp10;
  double inf;
  if (value > 0) {
    exp10 = (int) ceil(log10(value));
    inf   = INFINITY;
  } else if (value < 0) {
    exp10 = (int) ceil(log10(-value));
    inf   = -INFINITY;
  } else
    return;
  printf("exp10 = %d\n", exp10);

  double sig10 = value / pow(10, exp10);
  printf("sig10 = %g\n", sig10);

  double to_round = nextafter(sig10 * pow(10, precision), inf);
  printf("to round = %g\n", to_round);

  double rounded = round(to_round);
  printf("rounded = %g\n", rounded);

  double fl = pow(10, exp10) * rounded / pow(10, precision);
  printf("fl(value) = fl(%g) = %g, precision = %u\n", value, fl, precision);
}

void
print_fl_product(double m, double a, unsigned int precision) {
  printf("fl(fl(m)fl(%g)) = fl(%g x %g) = %g\n",
         a,
         fl(m, precision),
         a,
         fl(fl(m, precision) * a, precision));
}

int
main(void) {

  printf("fl(%g/%g) = fl(%g) = %g\n", 3., 80., 3. / 80., fl(3. / 80, 2));

  printf("fl(%g/%g) = fl(%g) = %g\n", -3., 80., -3. / 80., fl(-3. / 80, 2));

  double       a         = 89;
  double       b         = 47;
  double       m         = a / b;
  unsigned int precision = 3;

  printf("fl(m) = fl(%g/%g) = fl(%g) = %g\n", a, b, m, fl(m, precision));

  print_fl_product(m, 47, 3);
  print_fl_product(m, 28, 3);
  print_fl_product(m, 19, 3);

  printf("fl[%g - fl(fl(m)fl(%g))] = fl(%g - %g) = %g\n",
         a,
         47.,
         a,
         fl(fl(m, 3) * fl(47, 3), 3),
         fl(a - fl(fl(m, 3) * fl(47., 3), 3), 3));

  printf("y = fl(%g/%g) = %g\n", .1, .1, fl(.1 / .1, 3));
  printf("x = fl((%g - %g)/%g) = fl(%g/%g) = %g\n",
         19.,
         28.,
         47.,
         (19. - 28.),
         47.,
         fl((19. - 28.) / 47., 3));

  return EXIT_SUCCESS;
}
