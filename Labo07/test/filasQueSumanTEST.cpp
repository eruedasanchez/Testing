#include "../src/filasQueSuman.h"
#include "../lib/gtest.h"

TEST(filasQueSumanTEST, PrimerCaso) {
    vector<vector<int>> m;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    m.push_back(v1);

    vector<int> v2;
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(0);
    m.push_back(v2);

    vector<int> v3;
    v3.push_back(5);
    v3.push_back(4);
    v3.push_back(3);
    m.push_back(v3);

    vector <int> vec = {1 ,2 ,3, 2, 4, 0};
    int n = 6;
    vector<int> result = filasQueSumanN(m,n);
    EXPECT_EQ(vec, result);
}