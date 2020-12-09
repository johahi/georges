#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <cmath>
#include <array>

template<size_t N>
struct vec {
    std::array<float, N> data;
    float& operator[](int i) {
        return this->data[i];
    }
    const float& operator[](int i) const {
        return this->data[i];
    } 
};

struct vec2 : vec<2> {
    constexpr vec2() : vec<2>({0.0f, 0.0f}) {}
    constexpr vec2(float x, float y) : vec<2>({x, y}) {}
    constexpr vec2(const vec<2>& v) : vec<2>({v[0], v[1]}) {}
};

struct vec3 : vec<3> {
    constexpr vec3() : vec<3>({0.0f, 0.0f, 0.0f}) {}
    constexpr vec3(float x, float y, float z) : vec<3>({x, y ,z}) {}
    constexpr vec3(const vec<3>& v) : vec<3>({v[0], v[1], v[2]}) {}
    constexpr vec3(const vec<2>& xy, float z) : vec<3>({xy[0], xy[1], z}) {}
};

template<size_t N>
vec<N> operator+(const vec<N>& lhs, const vec<N>& rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs[i] + rhs[i];
    return res;
}

template<size_t N>
vec<N> operator+(float lhs, const vec<N>& rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs + rhs[i];
    return res;
}

template<size_t N>
vec<N> operator+(const vec<N>& lhs, float rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs[i] + rhs;
    return res;
}

template<size_t N>
vec<N> operator-(const vec<N>& lhs, const vec<N>& rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs[i] - rhs[i];
    return res;
}

template<size_t N>
vec<N> operator-(float lhs, const vec<N>& rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs - rhs[i];
    return res;
}

template<size_t N>
vec<N> operator-(const vec<N>& lhs, float rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs[i] - rhs;
    return res;
}

template<size_t N>
vec<N> operator*(const vec<N>& lhs, const vec<N>& rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs[i] * rhs[i];
    return res;
}

template<size_t N>
vec<N> operator*(float lhs, const vec<N>& rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs * rhs[i];
    return res;
}

template<size_t N>
vec<N> operator*(const vec<N>& lhs, float rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs[i] * rhs;
    return res;
}

template<size_t N>
vec<N> operator/(const vec<N>& lhs, const vec<N>& rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs[i] / rhs[i];
    return res;
}

template<size_t N>
vec<N> operator/(float lhs, const vec<N>& rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs / rhs[i];
    return res;
}

template<size_t N>
vec<N> operator/(const vec<N>& lhs, float rhs) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = lhs[i] / rhs;
    return res;
}

template<size_t N>
vec<N> apply(const vec<N>& v, float (&func) (float)) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = func(v[i]);
    return res;
}

template<size_t N>
vec<N> vmax(const vec<N>& v, float x) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = std::max(v[i], x);
    return res;
}

template<size_t N>
vec<N> vclamp(const vec<N>& v, float lo, float hi) { 
    vec<N> res;
    for (auto i = 0; i < N; i++) res[i] = std::clamp(v[i], lo, hi);
    return res;
}

template<size_t N>
float len(const vec<N>& v) { 
    float res = 0.0f;
    for (auto i = 0; i < N; i++) res += v[i] * v[i];
    return sqrtf(res);
}

template<size_t N>
float dot(const vec<N>& lhs, const vec<N>& rhs) { 
    float res = 0.0f;
    for (auto i = 0; i < N; i++) res += lhs[i] * rhs[i];
    return res;
}


template<size_t N>
vec<N> normalize(const vec<N>& v) { 
    float vlen = len(v);
    if (vlen == 0) return v;
    return v/vlen;
}

template <size_t N>
std::ostream& operator<<(std::ostream& o, const vec<N>& v) {
    copy(v.data.cbegin(), v.data.cend(), std::ostream_iterator<float>(o, " "));
    return o;
}

#endif