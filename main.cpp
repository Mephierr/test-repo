﻿#include <vector>
#include <functional>
#include <iostream>
#include "candle.h"


//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

//Тест 1.1: Проверка зеленой свечи
bool body_contains_test_1()
{
  Candle candle(Price(10.0), Price(12.0), Price(9.0), Price(11.0));
  if (candle.body_contains(Price(10.0)) == false) // на границе (открытие)
  {
    return false;
  }
  else if (candle.body_contains(Price(11.0)) == false) // на границе (закрытие)
  {
    return false;
  }
  else if (candle.body_contains(Price(10.5)) == false) // внутри тела
  {
    return false;
  }
  else if (candle.body_contains(Price(9.0)) == true) // ниже тела
  {
    return false;
  }
  else if (candle.body_contains(Price(12.0)) == true) // выше тела
  {
    return false;
  }
  return true;
}

//Тест 1.2: Проверка красной свечи
bool body_contains_test_2()
{
  Candle candle(Price(11.0), Price(12.0), Price(10.0), Price(9.0));
  if (candle.body_contains(Price(10.0)) == false) // на границе (низ)
  {
    return false;
  }
  else if (candle.body_contains(Price(9.0)) == false) // на границе (верх)
  {
    return false;
  }
  else if (candle.body_contains(Price(10.5)) == false) // внутри тела
  {
    return false;
  }
  else if (candle.body_contains(Price(12.0)) == true) // выше тела
  {
    return false;
  }
  else if (candle.body_contains(Price(8.0)) == true) // ниже тела
  {
    return false;
  }
  return true;
}

//Тест 1.3: Проверка свечи с одинаковыми значениями открытия и закрытия
bool body_contains_test_3()
{
  Candle candle(Price(10.0), Price(10.0), Price(10.0), Price(10.0));
  if (candle.body_contains(Price(10.0)) == false) // на границе (открытие и закрытие)
  {
    return false;
  }
  else if (candle.body_contains(Price(9.5)) == true) // ниже тела
  {
    return false;
  }
  else if (candle.body_contains(Price(10.5)) == true) // выше тела
  {
    return false;
  }
  return true;
}

//Тест 2.1: Цена находится в пределах свечи
bool contains_test_1()
{
  Candle candle(Price(100), Price(200), Price(150), Price(180));
  if (candle.contains(Price(150)) == false) // на границе
  {
    return false;
  }
  else if (candle.contains(Price(180)) == false) // на границе
  {
    return false;
  }
  else if (candle.contains(Price(170)) == false) // внутри
  {
    return false;
  }
  return true;
}

// Тест 2.2: Цена ниже нижней границы свечи
bool contains_test_2()
{
  Candle candle(Price(100), Price(200), Price(150), Price(180));
  if (candle.contains(Price(140)) == true) // ниже нижней границы
  {
    return false;
  }
  return true;
}

// Тест 2.3: Цена выше верхней границы свечи
bool contains_test_3()
{
  Candle candle(Price(100), Price(200), Price(150), Price(180));
  if (candle.contains(Price(210)) == true) // Выше верхней границы
  {
    return false;
  }
  return true;
}

// Тест 3.1: Полный размер свечи с нормальными значениями
bool full_size_test_1()
{
  Candle candle(Price(100), Price(200), Price(150), Price(180));
  return candle.full_size()== 50.0; // 200 - 150 = 50
}

// Тест 3.2: Полный размер свечи, когда low и high равны
bool full_size_test_2()
{
  Candle candle(Price(100), Price(150), Price(150), Price(150));
  return candle.full_size()== 0.0; // 150-150 =0
}

// Тест 3.3: Полный размер свечи с отрицательными значениями
bool full_size_test_3()
{
  Candle candle(Price(-100), Price(-50), Price(-150), Price(-120));
  return candle.full_size()== 100.0; // -50 -(-150) = 100;
}

// Тест 4.1: Размер тела свечи с нормальными значениями
bool body_size_test_1()
{
  Candle candle(Price(100), Price(200), Price(150), Price(180));
  return candle.body_size() == 80.0; // |100 - 180| = 80
}

// Тест 4.2: Размер тела свечи, когда open и close равны
bool body_size_test_2()
{
  Candle candle(Price(150), Price(200), Price(100), Price(150));
  return candle.body_size() == 0.0; // |150 - 150| = 0
}

// Тест 4.3: Размер тела свечи с отрицательными значениями
bool body_size_test_3()
{
  Candle candle(Price(-100), Price(-50), Price(-150), Price(-120));
  return candle.body_size() == 20.0; // |-100 - (-120)| = 20
}

// Тест 5.1: Свеча закрывается ниже открытия (красная свеча)
bool is_red_test_1()
{
  Candle candle(Price(200), Price(250), Price(150), Price(180)); // close < open
  return candle.is_red();
}

// Тест 5.2: Свеча закрывается выше открытия (не красная свеча)
bool is_red_test_2()
{
  Candle candle(Price(100), Price(150), Price(90), Price(120)); // close > open
  return !candle.is_red();
}

// Тест 5.3: Свеча закрывается на уровне открытия (не красная свеча)
bool is_red_test_3()
{
  Candle candle(Price(150), Price(200), Price(100), Price(150)); // close == open
  return !candle.is_red();
}

// Тест 6.1: Свеча закрывается выше открытия (зеленая свеча)
bool is_green_test_1()
{
  Candle candle(Price(100), Price(150), Price(90), Price(120)); // close > open
  return candle.is_green();
}

// Тест 6.2: Свеча закрывается ниже открытия (не зеленая свеча)
bool is_green_test_2()
{
  Candle candle(Price(200), Price(250), Price(150), Price(180)); // close < open
  return !candle.is_green();
}

// Тест 6.3: Свеча закрывается на уровне открытия (не зеленая свеча)
bool is_green_test_3()
{
  Candle candle(Price(150), Price(200), Price(100), Price(150)); // close == open
  return !candle.is_green();
}

void initTests()
{
  tests.push_back(body_contains_test_1);
  tests.push_back(body_contains_test_2);
  tests.push_back(body_contains_test_3);
  tests.push_back(contains_test_1);
  tests.push_back(contains_test_2);
  tests.push_back(contains_test_3);
  tests.push_back(full_size_test_1);
  tests.push_back(full_size_test_2);
  tests.push_back(full_size_test_3);
  tests.push_back(body_size_test_1);
  tests.push_back(body_size_test_2);
  tests.push_back(body_size_test_3);
  tests.push_back(is_red_test_1);
  tests.push_back(is_red_test_2);
  tests.push_back(is_red_test_3);
  tests.push_back(is_green_test_1);
  tests.push_back(is_green_test_2);
  tests.push_back(is_green_test_3);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
