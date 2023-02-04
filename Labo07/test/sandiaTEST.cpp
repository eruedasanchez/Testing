#include "../src/sandia.h"
#include "../lib/gtest.h"

TEST(SandiaTest, PorcionesPares) {
    int n = 6;
    bool result = sandia(n);
    EXPECT_TRUE(result);
}

TEST(SandiaTest, PorcionesImpares) {
    int n = 9;
    bool result = sandia(n);
    EXPECT_FALSE(result);
}