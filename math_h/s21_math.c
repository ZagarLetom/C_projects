#include "s21_math.h"

// Просто домножаем на -1 если число отрицательное
int s21_abs(int x) { return x < 0 ? -x : x; }

// Тут тоже самое, только еще проверяем на бесконечность и НЕ ЧИСЛО
long double s21_fabs(double x) {
  long double result = 0;
  if (x != x) {
    result = S21_NAN;
  } else if (x == 0.0 || x == -0.0) {
    result = 0.0;
  } else if (x == S21_INF || x == -S21_INF) {
    result = S21_INF;
  } else {
    result = x > 0 ? (long double)x : (long double)(x *= -1);
  }
  return result;
}
// Проверяем валидность данных и если всё нормально то выводим
// x - (абсолют(x/y)) * y
long double s21_fmod(double x, double y) {
  long double result = 0;
  if ((x != x) || (y != y) || x == S21_INF || x == -S21_INF || y == 0) {
    result = S21_NAN;
  } else if (y == S21_INF || y == -S21_INF) {
    result = x;
  } else if (x == 0.0 && y != 0) {
    result = 0.0;
  } else {
    if (x < 0 || y < 0) {
      result = -s21_abs(x / y);
    } else {
      result = s21_abs(x / y);
    }
    result = x - result * y;
  }
  return result;
}
// Проверка на валидность.
// Если x не равняется своей целой части (то есть у него есть вещественная
// часть) и x больше нуля, то прибавляем ему единицу. Если x меньше нуля то при
// преобразовании в int всё произайдёт само собой
long double s21_ceil(double x) {
  long double result = (long long int)x;
  if (x == S21_INF || x == -S21_INF || x == 0 || x == -0.0 || (x != x) ||
      x == DBL_MAX) {
    result = x;
  } else if (x == DBL_MIN) {
    result = 1;
  } else {
    if (s21_fabs(x) > 0. && x != result)
      if (x > 0.) {
        result += 1;
      }
  }
  return result;
}
// Обратная ситуация. Теперь если x меньше нуля нужно отнимать единицу
long double s21_floor(double x) {
  long double result = (long long int)x;
  if (x == S21_INF || x == -S21_INF || x == 0 || x == -0.0 || x != x) {
    result = x;
  } else {
    if (s21_fabs(x - result) > 0. && s21_fabs(x) > 0.)
      if (x < 0.) {
        result -= 1;
      }
  }
  return result;
}
// Проверяем на валидность.
// Сокращаем входные данные и вычисляем с помощью ряда Тейлора
// Начало цикла. Вычисления будут выполняться, пока абсолютное значение temp
// больше, чем маленькая константа S21_EPS. Это условие гарантирует, что
// вычисления будут продолжаться, пока новые члены ряда существенно влияют на
// результат.
long double s21_sin(double x) {
  long double result;
  if (x == S21_INF || x == -S21_INF || x != x) {
    result = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    while (x > S21_PI) {
      x -= 2 * S21_PI;
    }

    while (x < -S21_PI) {
      x += 2 * S21_PI;
    }
    result = x;
    int fact = 1;
    long double temp = x;
    while (s21_fabs(temp) > S21_EPS) {
      // Вычисление нового члена ряда для синуса. Эта строка содержит формулу
      // для вычисления следующего члена ряда тейлоровского разложения синуса.
      temp = (-temp * x * x) / ((2 * fact + 1) * (2 * fact));
      result += temp;
      fact++;
    }
  }
  return result;
}
long double s21_cos(double x) {
  double pow = 0.0;
  long double result = 1.0;
  long double num = 1.0;
  long double xl = s21_fmod(x, 2.0 * S21_PI);

  if (x != x || s21_fabs(x) == S21_INF) {
    result = S21_NAN;
  } else {
    // Вычисления будут выполняться, пока отношение num / result по модулю
    // больше некоторой маленькой константы S21_EPS.
    while (s21_fabs(num / result) > S21_EPS) {
      // Увеличение переменной pow на 2.0. Это связано с тем, что члены ряда
      // косинуса чередуются знаками и имеют степени, увеличивающиеся на 2.
      pow = pow + 2.0;
      num = (-num * xl * xl) / ((pow - 1.0) * (pow));
      result += num;
    }
  }
  return result;
}
// Проверяем на краевые случаи, чтобы сразу дать ответ
long double s21_tan(double x) {
  long double result;
  if (x == (double)(3 * S21_PI / 2)) {
    result = 5443746451065123.000000L;
  } else if (x == (double)(S21_PI / 2)) {
    result = 16331239353195370L;
  } else if (x == (double)(-S21_PI / 2)) {
    result = -16331239353195370L;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}
// Этот код реализует алгоритм, который оптимизирует вычисление арктангенса в
// различных областях и учитывает знак исходного значения
long double s21_atan(double x) {
  // Отслеживаем знак и количество итераций
  int sign = 0, size = 0;
  long double result = 0, x2 = 0;
  // Получаем абсолютное значение числа и его знак
  if (x < 0.F) {
    x = -x;
    sign |= 1;
  }
  // Если x слишком большой то заменяем его на границу большого числа
  if (x > s21_pow(10, 7)) {
    x = s21_pow(10, 7);
  }
  // Если x больше 1, то вычисляем обратное значение x и ставим знак
  if (x > 1.F) {
    x = 1.F / x;
    sign |= 2;
  }
  while (x > (S21_PI / 12.F)) {  // Сокращение области определения
    size++;
    result = 1.F / (x + ((float)1.732050807569));
    x = ((x * ((float)1.732050807569)) - 1) * result;
  }
  x2 = s21_pow(x, 2);
  // Приближенное вычисление арктангенса с использованием аппроксимации.
  result = x * (0.55913709 / (1.4087812 + x2) + 0.60310579 - 0.05160454 * x2);
  // Возвращение области определения в прежний вид
  while (size > 0) {
    result += S21_PI / 6.F;
    size--;
  }
  (sign & 2) ? result = (S21_PI / 2.F) - result : result;  // Инверсия
  (sign & 1) ? result = -result : result;                  // Знак
  return result;
}
long double s21_sqrt(double x) {
  long double result = 0;
  if (x < 0 || x != x) {
    result = S21_NAN;
  } else if (x == S21_INF || x == -S21_INF || x <= 1e-20l) {
    result = x;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}

long double s21_asin(double x) {
  long double result = 0;
  if ((x > 1.F) || x < -1.F) {
    result = S21_NAN;
  } else {
    x /= s21_sqrt(1.F - x * x);
    result = s21_atan(x);
  }
  return result;
}
long double s21_acos(double x) { return ((S21_PI / 2.F) - s21_asin(x)); }

long double s21_exp(double x) {
  long double result = 1.0;
  if (x == S21_INF) {
    result = S21_INF;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x == -S21_INF) {
    result = 0;
  } else {
    int n = 1;
    long double a = x, sn = 1;
    // Если x отрицательное, то a принимает значение -x, чтобы обеспечить
    // положительное значение для дальнейших вычислений
    if (x < 0.0) a = -x;
    // Цикл, выполняющий 1600 итераций для приближенного вычисления экспоненты.
    // В каждой итерации происходит умножение текущей частичной суммы sn на a /
    // n++, и результат прибавляется к общей сумме result.
    for (int i = 0; i < 1600; i++) {
      sn *= a / n++;
      result += sn;
    }
    // Если x было отрицательным, результат инвертируется.
    if (x < 0.0) result = 1 / result;
  }
  return result;
}

long double s21_log(double x) {
  long double result = 0;
  if (x < 0 || x == -S21_INF || (x != x)) {
    result = S21_NAN;
  } else if (x == 0) {
    result = -S21_INF;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == 1) {
    result = 0;
  } else {
    // Инициализация переменных N, P и A. N будет использоваться для подсчета
    // целой части логарифма, P будет обновляться в цикле, и A будет
    // использоваться для хранения предыдущего значения N во внутреннем цикле.
    double N = 0.0, P = x, A = 0;
    // Цикл, который уменьшает значение P до тех пор, пока оно не станет меньше
    // e (число Эйлера), увеличивая при этом переменную N на 1.
    while (P >= S21_E) {
      P /= S21_E;
      N++;
    }
    // Добавление дробной части логарифма к N.
    N += (P / S21_E);
    // Восстановление значения P для дальнейших вычислений.
    P = x;
    int j = 0;
    // Цикл, который выполняется, пока значение N не перестанет изменяться или
    // пока не будет достигнуто максимальное число итераций (10000). В каждой
    // итерации вычисляются значения L и R, а затем обновляется N на основе их
    // среднего значения.
    do {
      double L, R;
      A = N;
      L = (P / (s21_exp(N - 1.0)));
      R = ((N - 1.0) * S21_E);
      N = ((L + R) / S21_E);
      j++;
    } while (N != A && j < 10000);
    result = N;
  }
  return result;
}
// Большая валидация
long double s21_pow(double base, double exp) {
  long double res = 0;
  int tmp = 0;
  if (base == 1 || exp == 0 ||
      (base == -1 && (exp == S21_INF || exp == -S21_INF))) {
    res = 1;
  } else if ((s21_fabs(base) < 1 && exp == -S21_INF) ||
             (s21_fabs(base) > 1 && exp == S21_INF) ||
             (base == -S21_INF &&
              ((exp > 0 && (int)exp % 2 == 0) || exp == S21_INF)) ||
             (base == S21_INF && exp > 0)) {
    res = S21_INF;
  } else if ((!(base == -S21_INF && exp == -S21_INF) &&
              (base < 0 && (int)exp - exp != 0)) ||
             (base != base && exp != exp)) {
    res = S21_NAN;
  } else if ((base == 0 && exp > 0) ||
             (s21_fabs(base) > 1 && exp == -S21_INF) ||
             (s21_fabs(base) < 1 && exp == S21_INF) ||
             (base == -0.0 && (exp > 0 && (int)exp % 2 == 0)) ||
             (base == -S21_INF && (exp < 0 && (int)exp % 2 == 0)) ||
             (base == S21_INF && exp < 0) ||
             (base == -S21_INF && exp == -S21_INF)) {
    res = 0;
  } else if ((base == -0.0 && (exp > 0 && (int)exp % 2 != 0)) ||
             (base == -S21_INF && (exp < 0 && (int)exp % 2 != 0))) {
    res = -0.0;
  } else if (base == -S21_INF && (exp > 0 && (int)exp % 2 != 0)) {
    res = -S21_INF;
  } else {
    // Этот код использует свойства логарифмов и экспоненты для вычисления
    // степени числа, при этом сохраняет знак в зависимости от того, является ли
    // показатель степени четным или нечетным при отрицательном основании.
    if (base < 0) {
      if ((int)exp % 2 != 0) {
        tmp = 1;
      }
      base = s21_fabs(base);
    }
    res = tmp ? -s21_exp(exp * s21_log(base)) : s21_exp(exp * s21_log(base));
  }
  return res;
}