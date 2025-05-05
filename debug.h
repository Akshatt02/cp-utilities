//#define DEBUG_H
#ifndef DEBUG_H

#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <chrono>
using namespace std;
using namespace chrono;

#define DEBUG_RED          "\x1B[31m"
#define DEBUG_GREEN        "\x1B[32m"
#define DEBUG_YELLOW       "\x1B[33m"
#define DEBUG_BLUE         "\x1B[34m"
#define DEBUG_MAGENTA      "\x1B[35m"
#define DEBUG_CYAN         "\x1B[36m"
#define DEBUG_WHITE        "\x1B[37m"

#define DEBUG_RESET        "\x1B[0m"
#define DEBUG_VAR_COLOR    DEBUG_MAGENTA
#define DEBUG_VAL_COLOR    DEBUG_GREEN

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << "{"; __print(x.first); cerr << ", "; __print(x.second); cerr << "}";
}

template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << "[";
    for (auto &i : x) {
        if (f++) cerr << ", ";
        __print(i);
    }
    cerr << "]";
}

void _print() { cerr << DEBUG_RESET << endl; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#define dbg(x...) { cerr << DEBUG_VAR_COLOR << #x << " = " << DEBUG_VAL_COLOR; _print(x); }

template<typename T, typename T1>
T amax(T &a, T1 b) {
    if (b > a) a = b;
    return a;
}

template<typename T, typename T1>
T amin(T &a, T1 b) {
    if (b < a) a = b;
    return a;
}

#define dbg_time_start() auto __start = chrono::high_resolution_clock::now();
#define dbg_time_end() { cerr << "Execution Time: " << chrono::duration<double, milli>(chrono::high_resolution_clock::now() - __start).count() << " ms" << endl; }

#endif