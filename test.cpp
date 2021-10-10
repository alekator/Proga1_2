#include "Data.h"
#include "catch.hpp"
#include <cstring>

TEST_CASE("DateTime class tests", "[Square]") {
    Date a(10, 11, 1213, 21, 11, 11);
    REQUIRE(strcmp(a.Getstr(), "10/11/1213 21:11:11") == 0);
    Date b;
    REQUIRE(strcmp(b.Getstr(), "22/8/1337 11:12:13") == 0);
    Date c(b);
    REQUIRE(strcmp(b.Getstr(), c.Getstr()) == 0);

    c.Plus('y');
    REQUIRE(strcmp(c.Getstr(), "22/8/1338 11:12:13") == 0);
    c.Plus('M');
    REQUIRE(strcmp(c.Getstr(), "22/9/1338 11:12:13") == 0);
    c.Plus('d');
    REQUIRE(strcmp(c.Getstr(), "23/9/1338 11:12:13") == 0);
    c.Plus('h');
    REQUIRE(strcmp(c.Getstr(), "23/9/1338 12:12:13") == 0);
    c.Plus('m');
    REQUIRE(strcmp(c.Getstr(), "23/9/1338 12:13:13") == 0);
    c.Plus('s');
    REQUIRE(strcmp(c.Getstr(), "23/9/1338 12:13:14") == 0);

    a.Minus('y');
    REQUIRE(strcmp(a.Getstr(), "10/11/1212 21:11:11") == 0);
    a.Minus('M');
    REQUIRE(strcmp(a.Getstr(), "10/10/1212 21:11:11") == 0);
    a.Minus('d');
    REQUIRE(strcmp(a.Getstr(), "9/10/1212 21:11:11") == 0);
    a.Minus('h');
    REQUIRE(strcmp(a.Getstr(), "9/10/1212 20:11:11") == 0);
    a.Minus('m');
    REQUIRE(strcmp(a.Getstr(), "9/10/1212 20:10:11") == 0);
    a.Minus('s');
    REQUIRE(strcmp(a.Getstr(), "9/10/1212 20:10:10") == 0);

    a.SetY(1242);
    REQUIRE(strcmp(a.Getstr(), "9/10/1242 20:10:10") == 0);
    a.SetMonth(7);
    REQUIRE(strcmp(a.Getstr(), "9/7/1242 20:10:10") == 0);
    a.SetDay(13);
    REQUIRE(strcmp(a.Getstr(), "13/7/1242 20:10:10") == 0);
    a.SetH(7);
    REQUIRE(strcmp(a.Getstr(), "13/7/1242 7:10:10") == 0);
    a.SetMinute(30);
    REQUIRE(strcmp(a.Getstr(), "13/7/1242 7:30:10") == 0);
    a.SetSecond(50);
    REQUIRE(strcmp(a.Getstr(), "13/7/1242 7:30:50") == 0);

    Date d(22, 8, 1337, 7, 33, 1);
    Date e(1, 2, 2007, 2, 3, 4);
    Date f;
    f = d + e;
    REQUIRE(strcmp(f.Getstr(), "23/10/3344 9:36:5") == 0);
    Date h;
    h = e - d;
    REQUIRE(strcmp(h.Getstr(), "10/5/669 18:30:3") == 0);
}
