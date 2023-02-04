#include "../src/puntaje.h"
#include "../lib/gtest.h"

TEST(PuntajeTest, puntajeMenorADiezNoDivisiblePorTres) {
    int n = 7;
    int result = puntaje(n);
    EXPECT_EQ(4, result);
}

TEST(PuntajeTest, puntajeMenorADiezDivisiblePorTres) {
    int n = 6;
    int result = puntaje(n);
    EXPECT_EQ(22, result);
}

TEST(PuntajeTest, puntajeMayorADiezNoDivisiblePorTres) {
    int n = 11;
    int result = puntaje(n);
    EXPECT_TRUE(result);
}

TEST(PuntajeTest, puntajeMayorADiezDivisiblePorTres) {
    int n = 15;
    int result = puntaje(n);
    EXPECT_EQ(25, result);
}
